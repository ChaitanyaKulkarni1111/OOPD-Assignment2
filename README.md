## ASSIGNMENT 2B
This project is aimed at managing a library system, including functionalities such as handling users, journals, publications rank, library item and other related entities.

## Latest Commit Changes

### 1. **Missing Header Files Added**
Several necessary header files were included to fix issues related to unresolved references.

  - '#include "user.cpp"'
  - '#include "Journals.cpp"
  - '#include "Publications.cpp"

- **In `main.cpp`**:
  - #include <algorithm>
  - #include<vector>
  - #include "User.cpp"
  - #include "Library.cpp"
  - #include "ClassesFunctions.cpp"
  - #include "LibraryItem.cpp"
  - #include "functions.cpp"

### 2. **Syntax Error Fixed**
A syntax error involving a missing closing brace was fixed in `user.cpp`. The error was causing compilation issues and was resolved by adding the correct brace in the corresponding function.

---