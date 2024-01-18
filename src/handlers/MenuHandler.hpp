#include <memory>
#include <string>
#include <vector>

#include "CommandHandler.hpp"
namespace myClasses {
class MenuHandler {
 public:
  MenuHandler(int argc, char* argv[]);
  ~MenuHandler() = default;
  void anyToContinue(const std::string& message);
  void displayMenu(const std::vector<std::string>& menuItems);
  void runStartMenu(const std::vector<std::string>& menutItems);

 private:
  std::shared_ptr<CommandHandler> ptrCmdHandler;
};
}  // namespace myClasses
