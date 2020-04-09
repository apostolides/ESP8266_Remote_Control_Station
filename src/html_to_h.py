import os,sys

if __name__ == "__main__":

    if len(sys.argv) != 3:
        print(" Usage: {} <html file> <page_name>".format(__file__))

    page = "const char *{}=".format(sys.argv[2])

    with open(sys.argv[1]) as file:
        for line in file.readlines():
            page += "\"" + line.strip().replace("\"","\\\"") + "\"\n"
    page = page[:-1]
    page += ";"

    file_name = sys.argv[2] + ".h"
    header_name = (sys.argv[2]).upper() + "_H"

    with open(file_name,'w') as file:
        file.write("#ifndef {}\n#define {}\n".format(header_name,header_name))
        file.write(page)
        file.write("\n#endif")
