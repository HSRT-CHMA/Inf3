#print('Hello World')
import sys
import Parser
import P_Parser

if __name__ == '__main__':
    #print("Main-Method")
    # command line arguments can be altered via Debuggen > Exersice02 Eigenschaften > Debug > Script Arguments
    #if len(sys.argv) != 1 :
        #for i in range(len(sys.argv)):
            #if i == 0:
                #print("Programm-name: %s" % sys.argv[0])
            #else:
                #print("%d. Argument: %s" % (i,sys.argv[i]))
    #else :
        #print("ERROR : No command line arguments have been selected")

    print("______________________________________________________")
    #my_parser = Parser.Parser()
    
    my_other_parser = P_Parser.P_Parser()
    for i in range(1, len(sys.argv)):
        #print("Argument at position " + str(i) + " is " + my_other_parser.parseConstant(sys.argv[i]) )
        #print("%d. Argument: %s" % (i,sys.argv[i]) + " | The Result of parse() is " + str(my_other_parser.parse(sys.argv[i])))
        print(my_other_parser.parse(sys.argv[i]))