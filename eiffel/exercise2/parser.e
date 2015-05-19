note
	description: "Summary description for {PARSER}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	PARSER

create
	make

feature {NONE} -- Initialization

	make
			-- Initialization for `Current'.
		do
			print("New Parser %N%N")
			--print("Test isDigitWOZero 83 " + isDigitWOZero("83").out + "%N") -- True
			--print("Test isDigitWOZero 89a3 " + isDigitWOZero("89a3").out + "%N") -- False
			--print("Test isDigitWOZero ja " + isDigitWOZero("ja").out + "%N") -- False
			--print("Test isDigitWOZero 0 " + isDigitWOZero("0").out + "%N") -- False , because 0
			--print("Test 1 : " + isDigitWOZero('6').out) -- True
			--print("%NTest 2 : " + isDigitWOZero('a').out) -- False
			--print("%NTest 3 : " + isDigitWOZero('0').out) -- False !
			--print("%NTest 4 : " + isDigitWOZero('1').out) -- True

		end

feature -- "public" line_parse-Method, which should receives a string ( one line of command line input) and parses it by divideing in sub-expressions
	parse(finput : STRING)
	do
		--print("%N" + line_input)
		--print("%N parseConstant" + parseconstant(line_input).out)
		--print("Test on Factor %N")
		--parsefactor (line_input)
		---if attached parseconstant (line_input) as checked_constant  then
			--print(" True : " + checked_constant.constant_value.out)
		--else
			--print("False : Constant is Void")
		--end
		print("Zeile 42")
		if attached parseFactor (line_input) as checked_factor then
			print("%NTrue ; parseFactor returnt a valid EXPRESSION !")
		else
			print("Help")
		end
	end

feature {NONE} -- Is it a valid Equation ?
	parseEquation(input : STRING)
	Local
		all_equa : LIST[STRING]
	do
		print(input)
		all_equa := input.split ('=')
	end

feature -- Is it a valid Expression (A single TERM, a TERM + TERM + ...+ TERM) ?
	parseExpression(input : STRING)
	Local
		all_ex : LIST[STRING]
	do
		print(input + " in parseExpression %N ")
		all_ex := input.split ('+')
	end

feature -- Is it a valid Term (A single FACTOR, a FACTOR * FACTOR * .... * FACTOR  ?
	parseTerm(input : STRING)
	Local
		all_term : LIST[STRING]
	do
		--Contains input a * ? if not --> Term is single Factor
		if  then


		else
			print(input)
			all_term := input.split ('*')
		end
	end

feature -- Is it a valid Factor ? (A CONSTANT or an EXPRESSION) -- if input contains "(" and ")", its a EXPRESSION, else it is a CONSTANT
	parseFactor(input : STRING) : detachable EXPRESSION
	Local
		res_expression : detachable EXPRESSION
		-- expression-object to be used as result
		b : BOOLEAN
		-- To be used to check the Factor
		con : CONSTANT
		-- To be used for creating an Expression-Object ?
	do
		print(input)
		if (input.starts_with ("("))and (input.ends_with (")")) then -- Factor is an Expression
			parseexpression (input)
			print("-- >I'm a EXPRESSION ")

		else -- Factor is a CONSTANT
			if attached parseconstant (input) as checked_con then
				b := true
			else -- Factor = Void
				b := false
			end
		end

		if b then -- Constant is not Void
			create res_expression.make(input)
		else -- Constant is Void
			res_expression := Void
		end

		Result := res_expression

	end

feature -- Is it a valid Constant (e.g. 1 , 5, 50 , 9304858, 780007) Not valid : 0, 098, 00665 ect ?
	parseConstant(input : STRING) : detachable CONSTANT
	Local
		b : BOOLEAN
		-- to be used for Result
		char : CHARACTER
		-- A single Character for individual testing
		index : INTEGER
		-- is to be used as the index of the given String
		first_is_valid : BOOLEAN
		-- if this is true, the first number is a digitWOZero and thereby valid
		res_constant : detachable CONSTANT
		-- The constant-object that gets returnt; if valid it contains the value of the constant; if not it is Void
	do
		-- Is false by default, but needs to be true before loop, so b := b and isitdigit(char) works correct
		b := true
		-- Check first index
		first_is_valid := isDigitWOZero (input.item (1))
		--print("%NZeile 97 : " + first_is_valid.out)

		if input.count = 1 then
			b := first_is_valid
		else -- Check index 2 to n if first is valid
			if first_is_valid then
				from
					index := 2
				until
					index > input.count
				loop
					char := input.item (index)
					--print("%NZeile 109 : " + index.out)
					b := b and isitdigit(char)
					--print("%NZeile 111 : " + b.out)
					index := index + 1
				end
			else
				b := false
			end
		end

		if b then
			create res_constant.make(input)
		else
			res_constant := Void
		end
		Result := res_constant
	end

feature -- Is this character a Digit (0 to 9) ?
	isItDigit(char : CHARACTER) : BOOLEAN
	do
		Result := char.is_digit
		-- is_digit : BOOLEAN checks if character is an digit from 0 to 9
	end

feature -- Is this character a DigitWOZero aka 1 2 3 4 5 6 7 8 9 ?
	isDigitWOZero(char : CHARACTER) : BOOLEAN
	Local
		b : BOOLEAN
		null_char : CHARACTER
		-- to be used for the Result
	do
		null_char := '0'
		if char.is_digit then
			if not char.item.is_equal (null_char.item) then -- if given char is not equal to 0 (char.item is the character-value)
				b := true
			end
		else
			b := false
		end

		Result := b
	end



--feature -- Is it a valid Digit (0, 1 - 9) ?
	--isItDigit(input : STRING): BOOLEAN
	--Local
		--b : BOOLEAN
		--index : INTEGER
		--char : CHARACTER
	--do
		--b := true

		--from
			--index := 1
		--until
			--index = input.count
			-- count: INTEGER -- String length which is also the maximum valid index
		--loop
			--char := input.item (index)
			--b := b and char.is_digit
			--print(b.out + "%N")
			--index := index + 1
			--print(index.out + "%N")
		--end
		-- is_digit : BOOLEAN checks if character is an digit from 0 to 9
		--Result := b
	--end


--feature -- Is String a valid DigitWithOutZero (1 - 9) ?
	--isDigitWOZero(input : STRING) : BOOLEAN
	--do
		--Result := false
	--end



end
