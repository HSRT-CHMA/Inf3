using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Exercise02{
    class Program{
        /*
         * Main for Parser Execution
         */ 
        static void Main(string[] args){
            // New Parser Instance
            Parser parser = new Parser();
            // If args is empty and no parms
            if (args[0] == null){
                Console.WriteLine("Error: Input is empty.No Parameters.");
            }else{
                // If first args is file and args length > 1
                if (args[0].Equals("file") && args.Length > 1){
                    if (File.Exists(args[1])){
                        // New Instance of Streamreader for reading a.txt stored in Project-Under-Folder Debug
                        using (StreamReader reader = new StreamReader(args[1])){
                            // Read all until the End of the File 
                            while ((args[1] = reader.ReadLine()) != null){
                                parser.Parse(args[1]);
                            }
                        }
                    }else{
                        Console.WriteLine("Error: File does not exist.");
                    }
                }else{
                    // If file have no path
                    if (args[0].Equals("file") && args.Length == 1){
                        Console.WriteLine("Error: No path to file.");
                    }else{
                        // If args > 1, we have too many parms
                        if (args.Length > 1){
                            Console.WriteLine("Error: Too Many Parameters.");
                        }else{
                            // If args == 1 we can parse
                            if (args.Length == 1){
                                parser.Parse(args[0]);
                            }
                        }

                    }
                }
            }
            // Waiting for Userinput
            System.Console.ReadKey(); 
        }
    }
}
