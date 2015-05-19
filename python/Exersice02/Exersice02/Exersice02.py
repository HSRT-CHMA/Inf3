#print('Hello World')
import sys
import Parser

if __name__ == '__main__':
    #print("Main-Method")
    # command line arguments can be altered via Debuggen > Exersice02 Eigenschaften > Debug > Script Arguments
    if len(sys.argv) != 1 :
        for i in range(len(sys.argv)):
            if i == 0:
                print("Programm-name: %s" % sys.argv[0])
            else:
                print("%d. Argument: %s" % (i,sys.argv[i]))
    else :
        print("ERROR : No command line arguments have been selected")

    print("______________________________________________________")
    my_parser = Parser.Parser()
    for i in range(1, len(sys.argv)):
        #print(my_parser.parse(sys.argv[i]))
        print(my_parser.parse(sys.argv[i]))