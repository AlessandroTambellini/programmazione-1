#include <iostream>
#include <fstream>

using namespace std;

const int MAX_LENGTH = 256;

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Usage: exercise1.out <input> <output>" << endl;
    exit(1);
  }

  fstream input, output;

  input.open(argv[1], ios::in);
  if (input.fail())
  {
    cout << "Errore nell'apertura dello stream \"" << argv[1] << "\"!" << endl;
    exit(1);
  }

  output.open(argv[2], ios::out);
  if (output.fail())
  {
    cout << "Errore nell'apertura dello stream \"" << argv[2] << "\"!" << endl;
    input.close();
    exit(1);
  }

  char buffer[MAX_LENGTH];
  char maxRow[MAX_LENGTH] = {};
  int maxRowLength = -1;

  do
  {
    input.getline(buffer, MAX_LENGTH);

    int currentRowLength = 0;
    while (buffer[currentRowLength] != '\0')
    {
      cout << buffer[currentRowLength];
      currentRowLength += 1;
    }
    cout << currentRowLength << endl;

    // This is useless
    /*     if (currentRowLength == 0 && input.eof()) // end of file ==> the file was read
        {
          break;
        } */

    if (currentRowLength > maxRowLength)
    {
      for (int i = 0; i < currentRowLength; i++)
      {
        maxRow[i] = buffer[i];
      }
      maxRow[currentRowLength] = '\0';
      maxRowLength = currentRowLength;
    }

    output << currentRowLength << endl;

  } while (!input.eof());

  output << maxRow << " " << maxRowLength << endl;

  input.close();
  output.close();

  return 0;
}
