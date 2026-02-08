#pragma once
#include "gui/Application.h"
#include <gui/SplitterLayout.h>
#include <gui/View.h>
#include <dp/IDatabase.h>
#include <dp/IDataSet.h>
#include <dp/IDataSetDelegate.h>
#include <fo/FileOperations.h>

class Data : public gui::View{

    dp::IDatabasePtr db;
    std::vector<td::String> dataTypes;

    void populateDataTypes(){
        dp::IDataSetPtr pDS = db->createDataSet("SELECT * from data_type", dp::IDataSet::Execution::EX_MULT);
        int id;
        td::String name;
        dp::DSColumns cols(pDS->allocBindColumns(2));
        cols << "id" << id << "name" << name;
        if (!pDS->execute())
        {
            //show log
            pDS = nullptr;
            return;
        }

        while(pDS->moveNext()){
            dataTypes.push_back(name);
        }
    }

    void Connect(){
        gui::Application* pApp = getApplication();
        fo::fs::path dbPath;
        if (!pApp->getUserDataFilePath("measure.db", "Work/CppProjects/Telemetrija/res", dbPath))
        {
            mu::dbgLog("ERROR! Database file %s does not exist!", dbPath.c_str());
            return;
        }

        if (!db->connect(dbPath.string().c_str()))
            return;
    }

public:

    Data():db(dp::create(dp::IDatabase::ConnType::CT_SQLITE, dp::IDatabase::ServerType::SER_SQLITE3))
    {
        Connect();
        populateDataTypes();
    }

    Data(const Data&) = delete;
    Data& operator=(const Data&) = delete;

    static Data& instance() {
        static Data instance;  // constructed once, at first use
        return instance;
    }

    dp::IDatabasePtr& getDB(){return db;}

    std::vector<td::String> getTypes(){return dataTypes;}
};
