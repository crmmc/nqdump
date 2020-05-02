#include <iostream>
#include <string>
#include <stdexcept>
#include "qm/crypt.h"
#include "nm/ncmcrypt.h"
using namespace std;

bool convertFile(const string &filename);


int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: nqdump <input_file_path>" << endl;
        return 1;
    }
    string in = argv[1];
    if (convertFile(in) == true)
        return 0;
    else
        return -1;
}


bool convertFile(const string &filename) {
    auto pos = filename.rfind('.');
    if (pos == string::npos) {
        cerr << "Warning: no extname." << endl;
        return false;
    } else {
        auto base = filename.substr(0, pos);
        auto ext = filename.substr(pos + 1);
        if (ext == "qmcflac") {
            ext = ".flac";
            try {
                cout << "Dumping to flac: " << base + ext << endl;
                return convert(filename, base + ext);
            } catch (invalid_argument e) {
                cout << "exception: " << e.what() << endl;
            } catch (...) {
                cout << "unexcept exception!" << endl;
            }
            return false;
         } else if (ext == "qmc0" || ext == "qmc3") {
            ext = ".mp3";
            try {
                cout << "Dumping to mp3: " << base + ext << endl;
                return convert(filename, base + ext);
            } catch (invalid_argument e) {
                cout << "exception: " << e.what() << endl;
            } catch (...) {
                cout << "unexcept exception!" << endl;
            }
            return false;
         } else if (ext == "ncm") {
             try {
                NeteaseCrypt crypt(filename);
                crypt.Dump();
                crypt.FixMetadata();
                cout << "Dumped NCM: " << crypt.dumpFilepath() << endl;
            } catch (invalid_argument e) {
                cout << "exception: " << e.what() << endl;
            } catch (...) {
                cout << "unexcept exception!" << endl;
            }
            return true;
        } else {
            cerr << "Warning: unknown extname (support: ncm,qmcflac, qmc0, qmc3)."
                 << endl;
            return false;
        }
        return false;
    }
}
