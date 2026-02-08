#pragma once
#include <gui/View.h>
#include <gui/GridLayout.h>
#include <gui/GridComposer.h>
#include <gui/TableEdit.h>
#include <dp/IDatabase.h>
#include <dp/IDataSet.h>
#include <fo/FileOperations.h>
#include <gui/ImageView.h>
#include "Data.h"

class ViewTableEdit : public gui::View{
private:  
protected:
    gui::TableEdit table;
    //labels for the bottom row
    gui::GridLayout gl;
    //dp::IDatabasePtr db;
    dp::IDataSetPtr pDS;
    std::vector<td::String> dataTypes;

private:
    td::String formQuery(){
        td::String q="SELECT mi.idx AS measurement_index, m.run_id AS run";
        auto types=Data::instance().getTypes();
        for(int i=0; i<types.size();i++){
            q=q+", MAX(CASE WHEN dt.name = '"+types[i]+"' THEN m.value END) AS "+types[i];
        }
        q+=" FROM measurement m JOIN data_type dt ON m.data_type_id = dt.id JOIN measurement_index mi ON m.measurement_index_id = mi.id GROUP BY m.run_id, mi.id ORDER BY m.run_id, mi.idx;";
        return q;
    }
public:
    ViewTableEdit():
    table(td::Ownership::Extern, gui::TableEdit::RowNumberVisibility::VisibleOneBased)
    , gl(1,1)
    {
        gui::GridComposer gc(gl);
        gc.appendRow(table, 0);
        setLayout(&gl);
        populateData();
        initTable();
    }

protected:
    
    void initTable()
    {
        gui::Columns visCols(table.allocBindColumns(5));
        visCols << gui::ThSep::DoNotShowThSep << gui::Header(0, "#", "#")
        << gui::Header(1, "run", "run", 80, td::HAlignment::Right)
        << gui::Header(2, "vel", "vel", 80, td::HAlignment::Right)
        << gui::Header(3, "acc", "acc", 80, td::HAlignment::Right)
        << gui::Header(4, "temp", "temp", 80, td::HAlignment::Right);
        table.init(pDS);
    }

    void populateData()
    {
        //pDS = db->createDataSet("SELECT * from measurement", dp::IDataSet::Execution::EX_MULT);
        pDS = Data::instance().getDB()->createDataSet("SELECT mi.idx AS measurement_index, m.run_id AS run, MAX(CASE WHEN dt.name = 'velocity' THEN m.value END) AS velocity, MAX(CASE WHEN dt.name = 'acceleration' THEN m.value END) AS acceleration, MAX(CASE WHEN dt.name = 'temperature' THEN m.value END) AS temperature FROM measurement m JOIN data_type dt ON m.data_type_id = dt.id JOIN measurement_index mi ON m.measurement_index_id = mi.id GROUP BY m.run_id, mi.id ORDER BY m.run_id, mi.idx;", dp::IDataSet::Execution::EX_MULT);

        //pDS->setDelegate(&_delegate);
        //specify columns to obtain from the data provider
        dp::DSColumns cols(pDS->allocBindColumns(5));
        //cols << "id" << td::int4 << "data_type_id" << td::int4 << "measurement_index_id" << td::int4 << "value" << td::real4
        //<< "run_id" << td::int4;
        cols << "measurement_index" << td::int4 << "run"<< td::int4 << "velocity" << td::real4 << "acceleration" << td::real4 << "temperature" << td::real4;
        if (!pDS->execute())
        {
            //show log
            mu::dbgLog("d");
            pDS = nullptr;
            return;
        }
    }
    
};
