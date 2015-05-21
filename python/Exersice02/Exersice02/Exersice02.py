import sys
import Another_Parser
from os.path import exists

'''
This Method serves as the main-Method of this project : 
Methods receives arguments from the command line via sys.argv and checks if a valid number and order of parameters is given.
If this condition is met, the Method parses the given arguments via the Parser-Class of this Project. It is also able
to parse arguments from a given text-file if 'file' and a path are entered in the command line
'''
if __name__ == '__main__':    
    # ---> file C:\Users\Georgia\Desktop\commands.txt   # Location of file for Testing 
    p_another = Another_Parser.Another_Parser()
    # Calles the python module and then the actual class
    
    del(sys.argv[0])
    # First Parameter from Command Line is automatically a String about the programm; it gets deleted because its not important for this programm
    
    if len(sys.argv) == 0 :
        print("ERROR : No command line arguments have been selected")
    else : # If sys.argv really contains Parameters
        if sys.argv[0] == "file" or sys.argv[0] == "File":
            # Checking for keyword
            if len(sys.argv) == 2:
                if sys.argv[1].endswith(".txt") :
                    # File has to be ofthis type
                    if exists(sys.argv[1]) : 
                    # Returns True if the file with given path exists
                        tmp = ""
                        # Single line from given file
                        filename = ""
                        filename = sys.argv[1]
                        # The path to the file; defined in the second parameter
                        content = ""
                        # The complete content of the given file
                        content = open(filename)
                        # Opens the given file and reads content in this programm
                        for line in content :
                            print("Given input : "+ str(line))
                            #tmp = p.parse(line)
                            p_another.parse(line)
                            #print("Test : "+ str(tmp))
                            
                        content.close()
                        # Built-in Function for File-Handling
                    else :
                        print("Error: File-Path '" + sys.argv[2] + "' does not lead to an existing file. Check the file-location and the spelling")
                else :
                    print("Error: Expected path as second paramter, but current parameter is '" + sys.argv[1] + "'")
            else :
                print("Error: Only two parameters are allowed to use file-function. Current input contains " + str(len(sys.argv)) + " parameters.")
        else :
            # Normal Parsing of one line here
            if len(sys.argv) == 1:
                p_another.parse(sys.argv[0])
            else :
                print("Error: Only one parameter is allowed. Current input contains " + str(len(sys.argv)) + " parameters.")
    
