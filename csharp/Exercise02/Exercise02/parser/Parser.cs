using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Exercise02.expression;
namespace Exercise02.parser
{
        class Parser
        {

            public Expression<?> parse(String input){
                return;
            }

            private Expression<?> parseEquation(String eqString){
                return;
            }

            private Expression<float> parseExpression(String eqString){
                return ;
            }

            private Expression<float> parseTerm(String eqString){
                return ;
            }

            private Expression<float> parseFactor(String eqString){
                return ;
            }

            private Constant parseConstant(String eqString){
                return null;
            }

            private Boolean isDigit(String eqString){
                return false;
            }

            private Boolean isDigitWithoutZero(String eqString){
                return false;
            }
        }
}
