#include <string>
#include <vector>
#include <cstdlib>

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include "CommandHandler.hpp"
#include "Logger.hpp"
#include "MenuHandler.hpp"
#include "Utils.hpp"

using namespace myLibs;
using namespace myClasses;

const std::vector<std::string> projects = {"Temperatures", "project2", "example",
                                     "other"};

int main(int argc, char *argv[]) {
    try
    {
        // Create an instance.
        mongocxx::instance inst{};

        const auto uri = mongocxx::uri{CONNECTION_STRING};
        // Set the version of the Stable API on the client.
        mongocxx::options::client client_options;
        const auto api = mongocxx::options::server_api{mongocxx::options::server_api::version::k_version_1};
        client_options.server_api_opts(api);
        // Set up the connection and get a handle on the "admin" database.
        mongocxx::client conn{ uri, client_options };
        mongocxx::database db = conn["admin"];
        // Ping the database.
        const auto ping_cmd = bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1));
        db.run_command(ping_cmd.view());
        std::cout << "Pinged your deployment. You successfully connected to MongoDB!" << std::endl;
    }
    catch (const std::exception& e)
    {
        // Handle errors
        std::cout<< "Exception: " << e.what() << std::endl;
    }

    if (argc > 1) {
        Logger::getInstance().log("Program started with commands!", "Info");
        CommandHandler cmdHandler(argc, argv);
        Logger::getInstance().log(
                "Program ended after CommandHandler execution!",
                "Info");
        return 0;
    }

    Logger::getInstance().log("Program started without commands", "Info");
    MenuHandler menuHandler(argc, argv);
    menuHandler.anyToContinue("Hello there!");
    menuHandler.runStartMenu(projects);
    Logger::getInstance().log("Program ended after project execution!", "Info");
    return 0;
}
