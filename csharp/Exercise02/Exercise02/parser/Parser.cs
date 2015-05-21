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
         * Class Variables
         * parms:   Regex   rZero,r,rWOZero: Using for isItDigit.
         *          int     tmpMulti,tmpAdd: Using for parsing Adding und Mutliplication.
         *          Boolean problem        : Using to flag a Wrong eqString.
         */
        private Regex rZero = new Regex("[0]");
        private Regex r = new Regex("[0-9]");
        private Regex rWOZero = new Regex("[1-9]");
        private int tmpMulti = 1;
        private int tmpAdd = 0;
        private Boolean problem=false;
        /*
        * Design by Contract Definition
        * Invariants 
        * --> 
        */
        [ContractInvariantMethod]
        protected void ObjectInvariant(){
        }

        public String Parse(String eqString){
            String str = "";
            /*
             * Contract have to be false to be true to use Parse.And Output have to be != null
             * AllTests() calls all Methods to Check if the EBNF is correct
             * If anything is ok call recursivly ParseEquation() and so on
             * parms:   String  str: Used for Console Output
             *                  eqString: Input form program
             */
            AllTests(eqString);
            Contract.Requires(problem == false);
            tmpAdd = 0;
            tmpMulti = 1;
            str = ParseEquation(eqString);
            Contract.Ensures(str != null);
            return str;
        }

        private String ParseEquation(String eqString){
            String left = "", right = "", res = "";
            int resRight = 0, resLeft = 0;
            /*
             * ParseEquation() called by Parse() checks if eqString is an Equality input
             * Calls ParseExpression() when no "=" is in eqString
             * parms:   String  eqString: Input form program
             *                  left,right: SubString left and right from operator "=" 
             *                  res: return Result for Output
             *          int     resRight,ResLeft: temporary int values for Calculation        
             */
            if (eqString.Contains("="))
            {
                // Left Substring
                left = eqString.Substring(0, eqString.IndexOf("="));
                res = ParseExpression(left);
                resLeft += Convert.ToInt32(res);
                // Right Substring
                right = eqString.Substring(eqString.IndexOf("=") + 1, eqString.Length - (eqString.IndexOf("=") + 1));
                res = ParseExpression(right);
                resRight += Convert.ToInt32(res);
                // Checks Equality and Output for Console
                Console.WriteLine("Values are Equal ?: "+resLeft+"="+resRight+ ": " + isEqual(resLeft == resRight));
            }
            else
            {
                // no "=" = calls ParseExpression() and is Output for all other ParseMethods
                res = ParseExpression(eqString);
                Console.WriteLine(res+=" = of the Values "+eqString);
            }
            return res;
        }

        private String ParseExpression(String eqString){
            String left = "", right = "", res = "";
            /*
             * ParseExpression() called by ParseEquation() checks if eqString is an Expression input
             * Calls ParseTerm() when no "+" is in eqString
             * parms:   String  eqString: Input form program
             *                  left,right: SubString left and right from operator "+" 
             *                  res: return Result for Output
             *          int     tmpAdd: saves all left values
             */
            if (eqString.Contains("+") && !eqString.Contains("(") && !eqString.Contains(")"))
            {
                // SubString Left
                left = eqString.Substring(0, eqString.IndexOf("+"));
                tmpAdd += Convert.ToInt32(ParseExpression(left));
                // SubString Right
                right = eqString.Substring(eqString.IndexOf("+") + 1, eqString.Length - (eqString.IndexOf("+") + 1));
                if (right.Contains("+"))
                {
                    // if another "+" is in right Substring do Method again.
                    res = ParseExpression(right);
                }
                else
                {
                    // if all "+" are substringed save the result in res
                    res = res += (tmpAdd + Convert.ToInt32(ParseTerm(right)));
                }
            }
            else
            {
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
             * parms:   String  eqString: Input form program
             *                  left,right: SubString left and right from operator "*" 
             *                  res: return Result for Output
             *          int     tmpMulti: saves all left values
             */
            if (eqString.Contains("*") && !eqString.Contains("(") && !eqString.Contains(")"))
            {
                // SubString Left
                left = eqString.Substring(0, eqString.IndexOf("*"));
                tmpMulti *= Convert.ToInt32(ParseExpression(left));
                // SubString Right
                right = eqString.Substring(eqString.IndexOf("*") + 1, eqString.Length - (eqString.IndexOf("*") + 1));
                if (right.Contains("*"))
                {
                    // if another "*" is in right Substring do Method again.
                    res = ParseTerm(right);
                }
                else
                {
                    // if all "*" are substringed save the result in res
                    res = res + (tmpMulti * Convert.ToInt32(ParseTerm(right)));
                }
            }
            else
            {
                // no "*" or ["(" ")" is in] eqString = calls ParseFactor()
                res = ParseFactor(eqString);
            }
            return res;
        }

        private String ParseFactor(String eqString){
            String eqString1 = "", eqString2 = "", eqString3 = "", res = "";
            int cnt1 = 0, cnt2 = 0;
            tmpAdd = 0;
            tmpMulti = 1;
            /*
             * ParseFactor() called by ParseTerm() checks if eqString is an Factor input
             * Calls ParseConstant() when no "(" or ")" is in eqString
             * parms:   String  eqString: Input form program
             *                  eqString1,2,3: Temporar Strings
             *                  left,right: SubString left and right from operator "*" 
             *                  res: return Result for Output
             *          int     cnt1,2: charSum for Replacing in Substrings
             */

            if (eqString.Contains("(") && eqString.Contains(")"))
            {
                eqString1 = eqString.Substring(0, eqString.IndexOf(")"));
                foreach (char c in eqString1)
                {
                    cnt1++;
                }
                eqString3 = eqString.Substring(eqString.IndexOf(")") + 1, eqString.Length - (eqString.IndexOf(")") + 1));
                foreach (char c in eqString1)
                {
                    cnt2++;
                }
                eqString2 = eqString.Substring(cnt1, eqString.Length - cnt2);
                eqString2 = eqString2.Substring(1, eqString2.IndexOf(")"));
                if (eqString2.Contains("(") && eqString2.Contains(")"))
                {
                    res = ParseExpression(eqString2);
                }
                else
                {
                    if (eqString2.Contains(")"))
                    {
                        eqString2 = eqString2.Replace(")", "");
                        res = ParseExpression(eqString2);
                    }
                }
                eqString2 = eqString1 + res + eqString3;
                if (eqString2.Contains("(") && eqString2.Contains(")"))
                {
                    res = ParseExpression(eqString2);
                }
                else
                {
                    if (eqString2.Contains(")"))
                    {
                        eqString2 = eqString2.Replace(")", "");
                        res = ParseExpression(eqString2);
                    }
                }
                res = ParseExpression(eqString2);
            }
            else
            {
                res = ParseConstant(eqString);
            }
            return res;
        }

        private String ParseConstant(String eqString){
            String res = "";
            if (IsItDigit(eqString) == true)
            {
                res = eqString;
            }
            return res;
        }

        private Boolean IsItDigit(String eqString){
            Contract.Requires(eqString != null);
            if (r.IsMatch(eqString))
            {
                return true;
            }
            return false;
        }

        private Boolean IsDigitWOZero(String eqString){
            if (rWOZero.IsMatch(eqString))
            {
                return true;
            }
            return false;
        }

        private Boolean isZero(String eqString){
            if (rZero.IsMatch(eqString)){
                return true;
            }
            return false;
        }

        private Boolean wrongBracketAmount(String eqString){
            int cnt1 = 0;
            int cnt2 = 0;

            //Counts each Bracket "(" in counter1 and ")" in counter 2
            foreach (char c in eqString){
                if (c.Equals('(')){
                    cnt1++;
                }
                else
                {
                    if (c.Equals(')')){
                        cnt2++;
                    }
                }
            }
            //If amount of left brackets unequal the amount of the right brackets then prints out problem
            if (cnt1 != cnt2){
                Console.WriteLine("Error: Wrong Amoutn of Brackets.");
                problem = true;
            }
            return problem;
        }
        private bool oneBracketProblem(String eqString){
            //If eqString contains onle one bracket "("
            if ((eqString.Contains("(") && (!(eqString.Contains(")"))))){
                Console.WriteLine("Error: Input contains only one bracket");
                problem = true;
            }
            else
            {       //If eqString contains onle one bracket ")"
                if ((!(eqString.Contains("(")) && (eqString.Contains(")")))){
                    Console.WriteLine("Error: Input contains only one bracket");
                    problem = true;
                }
            }
            return problem;
        }

        private Boolean bracketsWrongOrderProblem(String eqString){
            //If Brackets are in the Wrong Order
            if (eqString.IndexOf(")") < eqString.IndexOf("(")){
                Console.WriteLine("Error: Brackets are in the Wrong Order");
                problem = true;
            }
            return problem;
        }

        private Boolean emptyBracketsProblem(String eqString){
            //If eqString contains empty brackets ")"
            if (eqString.IndexOf("(") == eqString.IndexOf(")") - 1){
                Console.WriteLine("Error: Input contains empty Brackets");
                problem = true;
            }
            return problem;
        }

        private Boolean noOperatorsLeftFromBracketsProblem(String eqString){
            int cnt = 0;
            String eqString2 = "";

            //loop if eqString contains several Brackets
            foreach (char c in eqString){
                cnt++;
                if (c.Equals('(')){
                    //When there is no Operator left from Bracket (
                    eqString2 = eqString.Substring(0, cnt - 1);
                    if (!eqString2.EndsWith("=") && !eqString2.EndsWith("*") && !eqString2.EndsWith("+") && !(eqString.IndexOf("(") == 0)){
                        problem = true;
                    }
                }
            }
            if (problem){
                Console.WriteLine("Error: Bracket ( doesn´t have an other Operator on the left");
            }
            return problem;
        }

        private Boolean noOperatorsRightFromBracketsProblem(String eqString){
            int cnt = 0;
            String eqString2 = "";

            foreach (char c in eqString){
                cnt++;
                if (c.Equals(')')){
                    //When there is no Operator right from Bracket )
                    eqString2 = eqString.Substring(0, cnt);
                    if (!(cnt == eqString.Length)){
                        if (!eqString2.EndsWith("=") && !eqString2.EndsWith("*") && !eqString2.EndsWith("+") && !eqString2.EndsWith("")){
                            problem = true;
                        }
                    }
                }
            }
            if (problem){
                Console.WriteLine("Error: Bracket ) doesn´t have an other Operator on the right");
            }
            return problem;
        }

        private Boolean noNumbersProblem(String eqString){
            //If eqString doesn´t contain numbers
            if ((eqString.Contains("+") && !r.IsMatch(eqString)) || (eqString.Contains("*") && !r.IsMatch(eqString)) || (eqString.Contains("=") && !r.IsMatch(eqString))){
                Console.WriteLine("Error: Input only contains Operators and No Numbers");
                problem = true;
            }
            return problem;
        }

        private Boolean noOperatorsProblem(String eqString){
            //If eqString doesn´t contain operators
            if (r.IsMatch(eqString) && (!eqString.Contains("+") && !eqString.Contains("*") && !eqString.Contains("="))){
                Console.WriteLine("Error: Input doesn´t contain any Operators");
                problem = true;
            }
            return problem;
        }

        private Boolean noNumberLeftOrRightPlus(String eqString){
            int cnt = 0;
            String eqString2 = "";

            foreach (char c in eqString){
                cnt++;
                if (c.Equals('+')){
                    //When + is on the beginning and doesn´t have a Number on the left
                    if ((eqString.IndexOf("+") - 1) == -1){
                        problem = true;
                    }
                    else
                    {
                        //When + is on the end and doesn´t have a number on the right
                        if (cnt == eqString.Length){
                            problem = true;
                        }
                        else
                        {
                            //When + is not on the beginning and doesn´t have a Number on the left
                            eqString2 = eqString.Substring(0, cnt - 1);
                            if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+")){
                                problem = true;
                            }
                            else
                            {
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
                Console.WriteLine("Error: Operator + doesn´t have a Number on the left or right");
            }
            return problem;
        }

        private Boolean noNumberLeftOrRightMultiply(String eqString){
            int cnt = 0;
            String eqString2 = "";

            foreach (char c in eqString){
                cnt++;
                if (c.Equals('*')){
                    //When * is on the beginning and doesn´t have a Number on the left
                    if ((eqString.IndexOf("*") - 1) == -1)
                    {
                        problem = true;
                    }
                    else
                    {
                        //When * is on the end and doesn´t have a number on the right
                        if (cnt == eqString.Length)
                        {
                            problem = true;
                        }
                        else
                        {
                            //When * is not on the beginning and doesn´t have a Number on the left
                            eqString2 = eqString.Substring(0, cnt - 1);
                            if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+")){
                                problem = true;
                            }
                            else
                            {
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
                Console.WriteLine("Error: Operator * doesn´t have a Number on the left or right");
            }
            return problem;
        }

        private Boolean noNumberLeftOrRightEqual(String eqString){
            int cnt = 0;
            String eqString2 = "";

            if (eqString.Contains("=")){
                //When = is at the beginning and doesn´t have a Number on the left
                if ((eqString.IndexOf("=") - 1) == -1){
                    Console.WriteLine("Error: Operator = doesn´t have a Number on the left");
                    problem = true;
                }
                else
                {
                    //When = is at the end and doesn´t have a number on the right
                    //index = eqString.IndexOf("=");
                    if (eqString.IndexOf("=") == eqString.Length - 1){
                        Console.WriteLine("Error: Operator = doesn´t have a Number on the right");
                        problem = true;
                    }
                    else
                    {
                        //When = is not at the end and doesn´t have a number on the left
                        eqString2 = eqString.Substring(0, eqString.IndexOf("="));
                        if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+")){
                            Console.WriteLine("Error: Operator = doesn´t have a Number on the left");
                            problem = true;
                        }
                        else
                        {
                            //When = is not at the beginning and doesn´t have a Number on the right
                            eqString2 = eqString.Substring(0, eqString.IndexOf("=") + 2);
                            if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+")){
                                Console.WriteLine("Error: Operator = doesn´t have a Number on the right");
                                problem = true;
                            }
                            else
                            {
                                foreach (char c in eqString){
                                    if (c.Equals('=')){
                                        cnt++;
                                    }
                                }
                                if (cnt > 1){
                                    //When eqString contains two =
                                    Console.WriteLine("Error: Input contains more than one =");
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

        private Boolean doubleZeroProblem(String eqString){
            String eqString2 = "";

            if (eqString.Contains("00")){
                //When 00 is on the beginning and doesn´t have a Number on the left
                if ((eqString.IndexOf("00") - 1) == -1){
                    Console.WriteLine("Error: Input cointains illegal Number 00");
                    problem = true;
                }
                else
                {
                    //When 00 is  not on the beginning and doesn´t have a number on the left
                    eqString2 = eqString.Substring(0, eqString.IndexOf("00"));
                    if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+")){
                        Console.WriteLine("Error: eqString cointains illegal Number 00");
                        problem = true;
                    }
                    else
                    {
                        //When 00 is at the end
                        if (eqString.IndexOf("00") == eqString.Length - 2 && (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+"))){
                            Console.WriteLine("Error: Input cointains illegal Number 00");
                            problem = true;
                        }
                    }
                }
            }
            return problem;
        }

        private Boolean zeroProblem(String eqString){
            String eqString2 = "";

            if (eqString.Contains("0")){
                eqString2 = eqString.Substring(0, eqString.IndexOf("0"));
                if (eqString2.EndsWith("=") || eqString2.EndsWith("*") || eqString2.EndsWith("+")){
                    Console.WriteLine("Error: Input cointains illegal Number 0");
                    problem = true;
                }
                else
                {
                    eqString = eqString.Substring(eqString2.Length + 1, eqString.Length - (eqString2.Length + 1));
                    problem = zeroProblem(eqString);
                }
            }
            return problem;
        }

        private Boolean illegalCharacters(String eqString){
            foreach (char c in eqString){
                //When eqString doesn´t contain any allowed characters
                if (!(r.IsMatch("" + c)) && !(c.Equals('(')) && !(c.Equals(')')) && !(c.Equals('+')) && !(c.Equals('*')) && !(c.Equals('='))){
                    Console.WriteLine("Error: Input conatins an illegal Character");
                    problem = true;
                }
            }

            return problem;
        }

        private Boolean isEqual(Boolean equal){
            Boolean isEqual = equal;
            return isEqual;
        }

        public Boolean AllTests(String eqString){
            if (illegalCharacters(eqString) == false && doubleZeroProblem(eqString) == false && oneBracketProblem(eqString) == false
                 && emptyBracketsProblem(eqString) == false && noNumbersProblem(eqString) == false && noOperatorsProblem(eqString) == false
                 && noNumberLeftOrRightPlus(eqString) == false && noNumberLeftOrRightMultiply(eqString) == false && noNumberLeftOrRightEqual(eqString) == false
                 && bracketsWrongOrderProblem(eqString) == false && noOperatorsLeftFromBracketsProblem(eqString) == false && noOperatorsRightFromBracketsProblem(eqString) == false
                 && zeroProblem(eqString) == false && wrongBracketAmount(eqString) == false){
                     problem = false;
            }
            else
            {
                problem = true;
            }
            return problem;
        }
    }
}
