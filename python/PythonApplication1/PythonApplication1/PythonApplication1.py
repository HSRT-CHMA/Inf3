import sys
from os.path import exists
import Parser1

if __name__ == '__main__':    
    # ---> file C:\Users\Georgia\Desktop\commands.txt   # Location of file for Testing 
    
    p = Parser1.Parser1()

    del(sys.argv[0])
    
    
    if len(sys.argv) == 0 :
        print("ERROR : No command line arguments have been selected")
    else :
        if sys.argv[0] == "file" or sys.argv[0] == "File":
            if len(sys.argv) == 2:
                if sys.argv[1].endswith(".txt") :
                    if exists(sys.argv[1]) : # Returns True if the file with given path exists
                        tmp = ""
                        # Single line from given file
                        filename = ""
                        filename = sys.argv[1]
                        # The path to the file; defined in the second parameter
                        content = ""
                        # The complete content of the given file
                        content = open(filename)
                        # Opens the given file and reads content in this programm
                        print("________________________________________________________________________________________________________")
                        for line in content :
                            print("Test : "+ str(line))
                            #tmp = p.parse(line)
                            p.parse(line)
                            #print("Test : "+ str(tmp))
                            
                        content.close()
                    else :
                        print("Error: File-Path '" + sys.argv[2] + "' does not lead to an existing file. Check the file-location and the spelling")
                else :
                    print("Error: Expected path as second paramter, but current parameter is '" + sys.argv[1] + "'")
            else :
                print("Error: Only two parameters are allowed. Current input contains " + str(len(sys.argv)) + " parameters.")
        else :
            # Normal Parsing of one line here
            if len(sys.argv) == 1:
                print(p.parse(sys.argv[0])) # CAUTION
                #print("Line 47")
            else :
                print("Error: Only one parameter is allowed. Current input contains " + str(len(sys.argv)) + " parameters.")
    

