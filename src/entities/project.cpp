#include "project.hpp"
namespace myProjects {
Project::Project(){}

Project::Project(
    const std::string& title,
    const int creationDate,
    const uint8_t majorVersion,
    const uint8_t minorVersion,
    const std::string& course,
    const std::string& description
  ){

}
const uint8_t Project::getMajorVersion() const{
  return this->majorVersion;
}
const uint8_t Project::setMajorVersion(const uint8_t newMajorVersion){
  this->majorVersion = newMajorVersion;
  return this->majorVersion;
}
const uint8_t Project::getMinorVersion() const{
  return this->minorVersion;
}
const uint8_t Project::setMinorVersion(const uint8_t newMinorVersion){
  this->minorVersion = newMinorVersion;
  return this->minorVersion;
}
const std::string& Project::getTitle(){
  return this->title;
}
const std::string& Project::setTitle(const std::string& newTitle){
  this->title = newTitle;
  return this->title;
}
const std::string& Project::getCourse(){
  return this->course;
}
const std::string& Project::setCourse(const std::string& newCourse){
  this->course = newCourse;
  return this->course;
}
const std::string& Project::getDescription(){
  return this->description;
}
const std::string& Project::setDescription(const std::string& newDescription){
  this->description = newDescription;
  return this->description;
}

}
