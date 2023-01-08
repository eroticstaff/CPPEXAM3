#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename _Container, template <typename T> class _fileReader,
          template <typename K> class _fileSaver>
class Solver : public _fileReader<_Container>, public _fileSaver<_Container> {
  using fileLoader = _fileReader<_Container>;
  using fileSaver = _fileSaver<_Container>;

public:
  void solve(const string &input, const string &output) {
    _Container container = fileLoader::load(input);
    _Container result = algorithm(container);
    fileSaver::save(output, result);
  }
private:
  _Container algorithm(const _Container &container) {
    cout << "Making some magic with data" << endl;
    return {};
  }
};

template <typename _Container> class datReader {
protected:
  _Container load(const string &path) {
    cout << "Loading file with datReader. File: " << path << endl;
    return {};
  }
};


template <typename _Container> class iniReader {
protected:
  _Container load(const string &path) {
    cout << "Loading file with iniReader. File: " << path << endl;
    return {};
  }
};


template <typename _Container> class xmlReader {
protected:
  _Container load(const string &path) {
    cout << "Loading file with datReader. File: " << path << endl;
    return {};
  }
};

template <typename _Container> class mvSaver {
protected:
  void save(const string &path, _Container data) {
    cout << "Saving data to file with mvSaver. File: " << path << endl;
  }
};


template <typename _Container> class pdfSaver {
protected:
  void save(const string &path, _Container data) {
    cout << "Saving data to file with pdfSaver. File: " << path << endl;
  }
};


int main(){
  Solver<vector<int>, iniReader, pdfSaver> solver;
  solver.solve("in.ini", "out.pdf");
}
