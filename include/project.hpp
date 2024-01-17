#include <cstdint>
#include <string>
namespace myProjects {
class Project {
public:
  Project();
  Project(
    const std::string& title,
    const int createionDate = -1,
    const uint8_t majorVersion = 0,
    const uint8_t minorVersion = 0,
    const std::string& course = "No course set",
    const std::string& description = "No description set"
  );
  const uint8_t getMajorVersion() const;
  const uint8_t setMajorVersion(const uint8_t newMajorVersion);
  const uint8_t getMinorVersion() const;
  const uint8_t setMinorVersion(const uint8_t newMinorVersion);
  const std::string& getTitle();
  const std::string& setTitle(const std::string& newTitle);
  const std::string& getCourse();
  const std::string& setCourse(const std::string& newCourse);
  const std::string& getDescription();
  const std::string& setDescription(const std::string& newDescription);
private:
  int8_t id = -1;
  int creationDate;
  uint8_t majorVersion = 0;
  uint8_t minorVersion = 0;
  std::string title = "No title set";
  std::string course = "No course set";
  std::string description = "No description set";

};
}  // namespace myProjects
