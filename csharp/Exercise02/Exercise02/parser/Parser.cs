using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics.Contracts;
using System.Text.RegularExpressions;

namespace Exercise02{
    class Parser{
        /*
         * Parser Class, parsing after EBNF
         * Class Variables
         * parms:   Regex   rZero,r,rWOZero: Using for isItDigit.Is Input a number.
         *          int     tmpMulti,tmpAdd: Using for parsing Adding und Mutliplication.
         *          Boolean problem        : Using to flag a Wrong eqString.
         */
        private Regex rZero = new Regex("[0]");
        private Regex r = new Regex("[0-9]");
        private int tmpMulti = 1;
        private int tmpAdd = 0;
        private Boolean problem=false;
        /*
        * Design by Contract Definition
        * Invariants 
        */
        [ContractInvariantMethod]
        protected void ObjectInvariant(){
        }

        public String Parse(String eqString){
            Contract.Requires(eqString != null);
            String str = "";
            /*
             * Contract have to be false to be true to use Parse.And Output have to be != null
             * AllTests() calls all Methods to Check if the EBNF is correct
             * If anything is ok call recursivly ParseEquation() and so on
             * parms:   String  str: Used for Console Output
             *                  eqString: Input from program
             */
            AllTests(eqString);
            Contract.Requires(!problem);
            tmpAdd = 0;
            tmpMulti = 1;
            if (problem){
                Console.WriteLine("There is a Problem with your Input,please check the Error explained above!");
                return "";
            }else{
                str = ParseEquation(eqString);
                Contract.Ensures(str != null);
                return str;
            }
        }

        private String ParseEquation(String eqString){
            String left = "", right = "", res = "";
            int resRight = 0, resLeft = 0;
            /*
             * ParseEquation() called by Parse() checks if eqString is an Equality input
             * Calls ParseExpression() when no "=" is in eqString
             * parms:   String  eqString: Input from program
             *                  left,right: SubString left and right from operator "=" 
             *                  res: return Result for Output
             *          int     resRight,ResLeft: temporary int values for Calculation        
             */
            if (eqString.Contains("=")){
                // Left Substring
                left = eqString.Substring(0, eqString.IndexOf("="));
                res = ParseExpression(left);
                resLeft += Convert.ToInt32(res);
                // Right Substring
                right = eqString.Substring(eqString.IndexOf("=") + 1, eqString.Length - (eqString.IndexOf("=") + 1));
                res = ParseExpression(right);
                resRight += Convert.ToInt32(res);
                // Checks Equality and Output for Console
                Console.WriteLine(IsEqual(resLeft == resRight)+" = "+eqString);
            }else{
                // no "=" = calls ParseExpression() and is Output for all other ParseMethods
                res = ParseExpression(eqString);
                Console.WriteLine(res + " = " + eqString);
            }
            return res;
        }

        private String ParseExpression(String eqString){
            String left = "", right = "", res = "";
            /*
             * ParseExpression() called by ParseEquation() checks if eqString is an Expression input
             * Calls ParseTerm() when no "+" is in eqString
             * parms:   String  eqString: Input from program
             *                  left,right: SubString left and right from operator "+" 
             *                  res: return Result for Output
             *          int     tmpAdd: saves all left values
             */
            if (eqString.Contains("+") && !eqString.Contains("(") && !eqString.Contains(")")){
                // SubString Left
                left = eqString.Substring(0, eqString.IndexOf("+"));
                tmpAdd += Convert.ToInt32(ParseExpression(left));
                // SubString Right
                right = eqString.Substring(eqString.IndexOf("+") + 1, eqString.Length - (eqString.IndexOf("+") + 1));
                if (right.Contains("+")){
                    // if another "+" is in right Substring do Method again.
                    res = ParseExpression(right);
                }else{
                    // if all "+" are substringed save the result in res
                    res = res + (tmpAdd + Convert.ToInt32(ParseTerm(right)));
                }
            }else{
                // no "+" or ["(" ")" is in] eqString = calls ParseTerm()
                res = ParseTerm(eqString);
            }
            return res;
        }

        private String ParseTerm(String eqString){
            String left = "", right = "", res = "";
            /*
             * ParseTerm() called by ParseExpression() checks if eqString is an Term input
             * Calls ParseFactor() when no "*" is in eqString
             * parms:   String  eqString: Input from program
             *                  left,right: SubString left and right from operator "*" 
             *                  res: return Result for Output
             *          int     tmpMulti: saves all left values
             */
            if (eqString.Contains("*") && !eqString.Contains("(") && !eqString.Contains(")")){
                // SubString Left
                left = eqString.Substring(0, eqString.IndexOf("*"));
                tmpMulti *= Convert.ToInt32(ParseExpression(left));
                // SubString Right
                right = eqString.Substring(eqString.IndexOf("*") + 1, eqString.Length - (eqString.IndexOf("*") + 1));
                if (right.Contains("*")){
                    // if another "*" is in right Substring do Method again.
                    res = ParseTerm(right);
                }else{
                    // if all "*" are substringed save the result in res
                    res = res + (tmpMulti * Convert.ToInt32(ParseTerm(right)));
                }
            }else{
                // no "*" or ["(" ")" is in] eqString = calls ParseFactor()
                res = ParseFactor(eqString);
            }
            return res;
        }

        private String ParseFactor(String eqString){
            /*
             * ParseFactor() called by ParseTerm() checks if eqString is an Factor input
             * Calls ParseConstant() when no "(" or ")" is in eqString
             * parms:   String  eqString: Input from program
             *                  eqString1,2,3: Temporar Strings 
             *                  res: return Result for Output
             *          int     cnt1,2,3: Amount for Replacing in Substrings
             * Extra Info       1=left;2=middle;3=right
             */             
            String eqString1 = "", eqString2 = "", eqString3 = "", res = "";
            int cnt1 = 0, cnt2 = 0, cnt3 = 0;
            tmpAdd = 0;
            tmpMulti = 1;
                
            // count number of Chars in eqString
            foreach(char c in eqString){
                if(c.Equals('(')){
                    cnt1 = cnt2;
                }
                cnt2++;
            }
            cnt2 = 0;
            // checks if eqString contains "(" and ")"
            if (eqString.Contains("(") && eqString.Contains(")")){
                // Substring from Begin until '(' into left
                eqString1 = eqString.Substring(0, cnt1);
                // Checking if index of '(' is bigger than of ')' to know from where to Substring and doesnt split the open bracket '(' with the closed Bracket ')'
                if (cnt1 > eqString.IndexOf(")")){
                    // Count number of Characters in eqString
                    foreach (char c in eqString){
                        if (c.Equals(')')){
                            // If Character equals '(' then the right counter gets the value of the middle counter
                            cnt3 = cnt2;
                        }
                        cnt2++;
                    }
                    cnt2 = 0;
                    // Substring from right counter until ')' and write it in right
                    eqString3 = eqString.Substring(cnt3 + 1, eqString.Length - (cnt3 + 1));
                }else{
                    // Substring from ')' until end and write it in right
                    eqString3 = eqString.Substring(eqString.IndexOf(")")+1,eqString.Length - (eqString.IndexOf(")")+1));
                }

                // Middle gets the Substrings from left and right
                eqString2 = eqString.Substring(cnt1,(eqString.Length)-cnt1);
                eqString2 = eqString2.Substring(eqString2.IndexOf("("),eqString2.IndexOf(")"));
                if(eqString2.Contains("(") && eqString2.Contains(")")){
                    // Removin Brackets
                    eqString2 = eqString2.Replace("(","");
                    eqString2 = eqString2.Replace(")","");
                    res = ParseExpression(eqString2);
                }else{ 
                    if(eqString2.Contains(")")){
                        // Removin Brackets
                        eqString2 = eqString2.Replace(")","");
                        res = ParseExpression(eqString2);
                    }else{
                        if(eqString2.Contains("(")){
                            // Removin Brackets
                            eqString2 = eqString2.Replace("(","");
                            res = ParseExpression(eqString2);
                        }else{
                            res = ParseExpression(eqString2);
                        }

                    }
                }
                // Substring before '(' and after ')' + left + result + right
                eqString2 = eqString1 + res + eqString3;
                res = ParseExpression(eqString2);
            }else{
                res = ParseConstant(eqString);
            }
            return res;
        }

        private String ParseConstant(String eqString){
            String res = "";
            /*
             * ParseConstant() called by ParseFactor() checks if eqString is an Constant input
             * Calls IsItDigit(): is eqString an Regex[0-9]?
             * parms:   String  eqString: Input from program
             *                  res: return Result for Output        
             */
            if (IsItDigit(eqString) == true)
            {
                res = eqString;
            }
            return res;
        }

        private Boolean IsItDigit(String eqString){
            /*
             * IsItDigit() called by ParseConstant() checking if eqString is number between 0-9
             * parms:   Regex   r:Numbers between 0-9
             *                  rZero: Number 0
             */
            if (r.IsMatch(eqString)){
                return true;
            }else{
                return false;
            }
        }

        private Boolean WrongBracketAmount(String eqString){
            // Checks if amount of opening and closing are equal
            // cnt1=left,cnt2=right
            int cnt1 = 0;
            int cnt2 = 0;

            //Counts Bracket "(" in cnt1 and ")" in cnt2
            foreach (char c in eqString){
                if (c.Equals('(')){
                    cnt1++;
                }else{
                    if (c.Equals(')')){
                        cnt2++;
                    }
                }
            }
            //If left brackets of cnt1 unequal right brackets of cnt2 problem = true
            if (cnt1 != cnt2){
                Console.WriteLine("Error: left Brackets unequal right brackets");
                problem = true;
            }
            return problem;
        }
        private bool OneBracketProblem(String eqString){
            //If eqString contains only opening bracket "("
            if ((eqString.Contains("(") && (!(eqString.Contains(")"))))){
                Console.WriteLine("Error: Input contains only one (opening) bracket");
                problem = true;
            }else{       //If eqString contains only closing bracket ")"
                if ((!(eqString.Contains("(")) && (eqString.Contains(")")))){
                    Console.WriteLine("Error: Input contains only one (closing) bracket");
                    problem = true;
                }
            }
            return problem;
        }

        private Boolean BracketsWrongOrderProblem(String eqString){
            //If Opening and Closing Brackets in wrong Order
            if (eqString.IndexOf(")") < eqString.IndexOf("(")){
                Console.WriteLine("Error: Opening and Closing Brackets are in the wrong Order");
                problem = true;
            }
            return problem;
        }

        private Boolean EmptyBracketsProblem(String eqString){
            // If eqString contains empty brackets "()"
            if (eqString.IndexOf("(") == eqString.IndexOf(")") - 1){
                Console.WriteLine("Error: Input contains empty Brackets '()'");
                problem = true;
            }
            return problem;
        }

        private Boolean NoOperatorsLeftFromBracketsProblem(String eqString){
            // Checks if an Operator is left from opening Bracket
            int cnt = 0;
            String eqString2 = "";

            // if eqString contains more Brackets = loop
            foreach (char c in eqString){
                cnt++;
                if (c.Equals('(')){
                    //When no Operator is left from opening Bracket "("
                    eqString2 = eqString.Substring(0, cnt - 1);
                    if (!eqString2.EndsWith("=") && !eqString2.EndsWith("*") && !eqString2.EndsWith("+") && !(eqString.IndexOf("(") == 0)){
                        problem = true;
                    }
                }
            }
            if (problem){
                Console.WriteLine("Error: Opening Bracket '(' doesn´t have an Operator on the left");
            }
            return problem;
        }

        private Boolean NoOperatorsRightFromBracketsProblem(String eqString){
            // Checks if an Operator is right from closing Bracket
            int cnt = 0;
            String eqString2 = "";

            // if eqString contains more Brackets = loop
            foreach (char c in eqString){
                cnt++;
                if (c.Equals(')')){
                    //When no Operator is right from closing Bracket ")"
                    eqString2 = eqString.Substring(0, cnt);
                    if (!(cnt == eqString.Length)){
                        if (!eqString2.EndsWith("=") && !eqString2.EndsWith("*") && !eqString2.EndsWith("+") && !eqString2.EndsWith("")){
                            problem = true;
                        }
                    }
                }
            }
            if (problem){
                Console.WriteLine("Error: Closing Bracket ')' doesn´t have an Operator on the right");
            }
            return problem;
        }

        private Boolean NoNumbersProblem(String eqString){
            //If eqString doesn´t contain numbers
            if ((eqString.Contains("+") && !r.IsMatch(eqString)) || (eqString.Contains("*") && !r.IsMatch(eqString)) || (eqString.Contains("=") && !r.IsMatch(eqString))){
                Console.WriteLine("Error: Input only contains Operators and no Numbers");
                problem = true;
            }
            return problem;
        }

        private Boolean NoNumberLeftOrRightPlus(String eqString){
            // Checks if there is a number left or right to "+"
            int cnt = 0;
            String eqString2 = "";

            // if eqString contains more "+" = loop
            foreach (char c in eqString){
                cnt++;
                if (c.Equals('+')){
                    //When + is on the beginning and doesn´t have a Number on the left
                    if ((eqString.IndexOf("+") - 1) == -1){
                        problem = true;
                    }else{
                        //When + is on the end and doesn´t have a number on the right
                        if (cnt == eqString.Length){
                            problem = true;
                        }else{
                            //When + is not on the beginning and doesn´t have a Number on the left
                            eqString2 = eqString.Substring(0, cnt - 1);
                            if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+")){
                                problem = true;
                            }else{
                                //When + is not on the end and doesn´t have a number on the right
                                eqString2 = eqString.Substring(0, cnt + 1);
                                if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+")){
                                    problem = true;
                                }
                            }
                        }
                    }
                }
            }
            if (problem){
                Console.WriteLine("Error: Operator '+' doesn´t have a Number on the left or right");
            }
            return problem;
        }

        private Boolean NoNumberLeftOrRightMultiply(String eqString){
            // Checks if there is a number left or right to "*"
            int cnt = 0;
            String eqString2 = "";

            // if eqString contains more "*" = loop
            foreach (char c in eqString){
                cnt++;
                if (c.Equals('*')){
                    //When * is on the beginning and doesn´t have a Number on the left
                    if ((eqString.IndexOf("*") - 1) == -1){
                        problem = true;
                    }else{
                        //When * is on the end and doesn´t have a number on the right
                        if (cnt == eqString.Length){
                            problem = true;
                        }else{
                            //When * is not on the beginning and doesn´t have a Number on the left
                            eqString2 = eqString.Substring(0, cnt - 1);
                            if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+")){
                                problem = true;
                            }else{
                                //When * is not on the end and doesn´t have a number on the right
                                eqString2 = eqString.Substring(0, cnt + 1);
                                if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+")){
                                    problem = true;
                                }
                            }
                        }
                    }
                }
            }
            if (problem){
                Console.WriteLine("Error: Operator '*' doesn´t have a Number on the left or right");
            }
            return problem;
        }

        private Boolean NoNumberLeftOrRightEqual(String eqString){
            // Checks if there is a number left or right to "="
            int cnt = 0;
            String eqString2 = "";

            if (eqString.Contains("=")){
                //When = is at the beginning and doesn´t have a Number on the left
                if ((eqString.IndexOf("=") - 1) == -1){
                    Console.WriteLine("Error: Operator = doesn´t have a Number on the left");
                    problem = true;
                }else{
                    //When = is at the end and doesn´t have a number on the right
                    //index = eqString.IndexOf("=");
                    if (eqString.IndexOf("=") == eqString.Length - 1){
                        Console.WriteLine("Error: Operator = doesn´t have a Number on the right");
                        problem = true;
                    }else{
                        //When = is not at the end and doesn´t have a number on the left
                        eqString2 = eqString.Substring(0, eqString.IndexOf("="));
                        if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+")){
                            Console.WriteLine("Error: Operator = doesn´t have a Number on the left");
                            problem = true;
                        }else{
                            //When = is not at the beginning and doesn´t have a Number on the right
                            eqString2 = eqString.Substring(0, eqString.IndexOf("=") + 2);
                            if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+")){
                                Console.WriteLine("Error: Operator = doesn´t have a Number on the right");
                                problem = true;
                            }else{
                                // if eqString contains more "=" = loop
                                foreach (char c in eqString){
                                    if (c.Equals('=')){
                                        cnt++;
                                    }
                                }
                                if (cnt > 1){
                                    //When eqString contains more than one "="
                                    Console.WriteLine("Error: Input contains more than one '='");
                                    problem = true;
                                    cnt = 0;
                                }
                            }
                        }
                    }
                }
            }
            return problem;
        }

        private Boolean DoubleZeroProblem(String eqString){
            // Checks if eqString contains an incorrect double Zero 
            String eqString2 = "";

            if (eqString.Contains("00")){
                //When the double Zero is on the beginning and doesn´t have a Number on the left
                if ((eqString.IndexOf("00") - 1) == -1){
                    Console.WriteLine("Error: Input cointains illegal double Zero at the Beginning");
                    problem = true;
                }else{
                    //When the double Zero is not on the beginning and doesn´t have a number on the left
                    eqString2 = eqString.Substring(0, eqString.IndexOf("00"));
                    if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+")){
                        Console.WriteLine("Error: eqString cointains illegal double Zero with no other Number on the left");
                        problem = true;
                    }else{
                        //When the double Zero is at the end
                        if (eqString.IndexOf("00") == eqString.Length - 2 && (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+"))){
                            Console.WriteLine("Error: Input cointains illegal double Zero at the End");
                            problem = true;
                        }
                    }
                }
            }
            return problem;
        }

        private Boolean ZeroProblem(String eqString){
            // Checks if eqString contains an incorrect Zero
            String eqString2 = "";

            if (eqString.Contains("0")){
                eqString2 = eqString.Substring(0, eqString.IndexOf("0"));
                if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+") || eqString2.EndsWith(""+r.IsMatch(eqString)) || eqString2.EndsWith("")){
                    Console.WriteLine("Error: Input cointains illegal Number Zero");
                    problem = true;
                }else{
                    eqString = eqString.Substring(eqString2.Length + 1, eqString.Length - (eqString2.Length + 1));
                    problem = ZeroProblem(eqString);
                }
            }
            return problem;
        }

        private Boolean IllegalCharacters(String eqString){
            // Checks if eqString contains illegal Characters
            // loop until arguments end
            foreach (char c in eqString){
                //When eqString doesn´t contain any allowed characters
                if (!(r.IsMatch("" + c)) && !(c.Equals('(')) && !(c.Equals(')')) && !(c.Equals('+')) && !(c.Equals('*')) && !(c.Equals('='))){
                    Console.WriteLine("Error: Input conatins an illegal Character");
                    problem = true;
                }
            }

            return problem;
        }

        private Boolean IsEqual(Boolean equal){
            // Checks if left and right equal
            Boolean isEqual = equal;
            return isEqual;
        }

        public Boolean AllTests(String eqString){
            /*
             * AllTests() called by Parse() to Test all incorrect Inputs
             * parms:   Boolean     probelm: if true EBNF isnt fulfilled
             */
            Contract.Requires(!problem);
            if (IllegalCharacters(eqString) == false && DoubleZeroProblem(eqString) == false && OneBracketProblem(eqString) == false
                 && EmptyBracketsProblem(eqString) == false && NoNumbersProblem(eqString) == false && NoNumberLeftOrRightPlus(eqString) == false 
                 && NoNumberLeftOrRightMultiply(eqString) == false && NoNumberLeftOrRightEqual(eqString) == false && BracketsWrongOrderProblem(eqString) == false 
                 && NoOperatorsLeftFromBracketsProblem(eqString) == false && NoOperatorsRightFromBracketsProblem(eqString) == false
                 && ZeroProblem(eqString) == false && WrongBracketAmount(eqString) == false){
                     problem = false;
            }else{
                problem = true;
            }
            return problem;
        }
    }
}
