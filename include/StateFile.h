// Copyright 2023 nicolò salimbeni
#ifndef StateFile_h
#define StateFile_h

#include <map>
#include <string>
#include <vector>

/*
The state file is a .txt file with the following format used to save useful
information inside strings:
# comments

key1: value1

key2: value2

key3: value 3
...

ATTENTION: The file should be pre-existing before executing the code; this class is intended for modification, not creation. Therefore, the first time, you should manually write an empty state file with all values set to a default (e.g., 0).
This is necessary because the class includes a check thatprevents retrieving the value of a key that doesn't exist. A potential enhancement in the future could involve addressing this specific situation.
*/

class StateFile
{
  public:
  explicit StateFile(std::string path);
  std::string ValueOf(std::string key); // return the value of the key string
  void        UpdateValueOf(std::string key,
                            std::string value); // update the value of key
  void        PrintAll();                       // write the current values on screen
  void        UpdateFile();                     // write the current values inside the file
  bool        Contains(std::string key);        // tell if a key is inside the file

  private:
  // cointains all lines, also comments
  std::vector<std::string> all_file;
  // contains only usefull information for the program
  std::map<std::string, std::string> info;
  // path to the state file
  std::string file_path;
};

#endif
