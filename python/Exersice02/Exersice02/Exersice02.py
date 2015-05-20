#print('Hello World')
import sys
import Parser
import P_Parser
from os.path import exists

if __name__ == '__main__':
    #print("Main-Method")
    # command line arguments can be altered via Debuggen > Exersice02 Eigenschaften > Debug > Script Arguments
    # file  C:\Users\Georgia\Desktop\commands.txt
    
    #if len(sys.argv) != 1 :
        #for i in range(len(sys.argv)):
            #if i == 0:
                #print("Programm-name: %s" % sys.argv[0])
            #else:
                #print("%d. Argument: %s" % (i,sys.argv[i]))
    #else :
        #print("ERROR : No command line arguments have been selected")

    my_other_parser = P_Parser.P_Parser()
    
    if len(sys.argv) == 1 :
        print("ERROR : No command line arguments have been selected")
    else :
        if sys.argv[1] == "file" or sys.argv[1] == "File":
            #sys.argv[0] is programm name
            if len(sys.argv) == 3 :
                # Capacity must be exactly 3 - programm name; file; path
                if sys.argv[2].endswith(".txt"):
                    if exists(sys.argv[2]) : # Returns True if the file with given path exists
                        # Opens the given file and reads content in 
                        filename = ""
                        # The path to the file; defined in the second parameter
                        content = ""
                        # The complete content of the given file
                        filename = sys.argv[2]
                        content = open(filename, 'r')
                        #print(content.readline())
                        #print(content.read())
                        # Reads the complete file in 
                        print("________________________________________________________________________________________________________")
                        for line in content :
                            tmp = my_other_parser.parse(line)
                            print("Test : "+ str(tmp))

                        content.close()
                    else :
                        print("Error: File-Path '" + sys.argv[2] + "' does not lead to an existing file. Check the file-location and the spelling")
                else :
                    print("Error: Expected path as second paramter, but current parameter is '" + sys.argv[2] + "'")
            else :
                print("Error: Only two parameters are allowed. Current input contains " + str(len(sys.argv)-1) + " parameters.") 
                # Minus one because of programm-name which count not as a user-given parameter
        else : 
            #Normal parsing 
            for i in range(1, len(sys.argv)):
                print("%d. Argument: %s" % (i,sys.argv[i]) + " | The Result of parse() is " + str(my_other_parser.parse(sys.argv[i])))
