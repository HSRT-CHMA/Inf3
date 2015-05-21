note
	description: "Summary description for {PARSER}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	PARSER

create
	make

feature {NONE}
	s : STRING


feature {NONE} -- Initialization

	make
		do
			create s.make_empty
		end

feature -- public
	parser(input : STRING)
		Local
			b : BOOLEAN
			i : INTEGER
		do
			input.prune_all (' ')
			s := input
			if s.is_empty
			then io.put_string ("String is empty")
			else
				if (not s.item(1).is_digit or s.item(1) = '0') and not (s.item(1) = '(')
				then io.put_string ("is not allowed at the first position")
				else
					if (not s.item(s.capacity).is_digit or s.item(s.capacity) = '0') and not (s.item(s.capacity) = ')')
					then io.put_string("is not allowed at the endposition")
					else
						if not (s.occurrences ('(') = s.occurrences (')'))
						then io.put_string("Open brackets must have the same numers of closed brackets")
						else
						--	if s.occurrences ('(') > 0 and not right_order_of_brackets
						--	then io.put_string("wrong order of brackets")
						--		else
									if empty_brackets
									then io.put_string ("No content between brackets")
									else
										if no_number_before_after_operator
										then io.put_string ("No number before and after operator")
										else
												if not_allowed_sign
												then io.put_string ("Character is not allowed")
												else
												if s.occurrences ('=') > 1
												then io.put_string ("Only one '=' is allowed")
												else
													io.put_string("The result is: " + parse_equation)
												end

										end

									end
						--	end

						end

					end

				end

			end
		end
		end




feature {NONE}
	parse_equation : STRING
		Local
			i : STRING
			left : INTEGER
			right : INTEGER
		do
			i := ""
			if s.occurrences ('=') = 0
			then i := parse_expression
			else
				if s.occurrences ('=') = 1
				then left := parse_expression.to_integer
					 s.remove(1)
					 right := parse_expression.to_integer
					 i := (left = right).out

				end

			end
			Result := i
		end


feature {NONE}
	parse_expression : STRING
		Local
			i : STRING
			left : INTEGER
			right : INTEGER
		do
			i := ""
			if s.occurrences('+') = 0
			then i := parse_term
			else
				if s.occurrences ('+') > 0
				then left := parse_term.to_integer
				i := left.out
				from
				until
					s.occurrences ('+') = 0 or s.item(1) /= '+'
				loop
					s.remove(1)
					right := parse_term.to_integer
					i := (i.to_integer + right).out
				end

				end
			end
			Result := i
		end



feature {NONE}
	parse_term : STRING
		Local
			i : STRING
			left : INTEGER
			right : INTEGER
		do
			if s.occurrences ('*') = 0
			then i := parse_factor
			else
				i := ""
				if s.occurrences ('*') > 0
				then left := parse_factor.to_integer
					 i := left.out
					 from
					 until
					 	s.occurrences ('*') = 0 or s.item(1) /= '*'
					 loop
					 	s.remove(1)
					 	right := parse_factor.to_integer
					 	i := (i.to_integer * right).out
					 end

				end

			end
			Result := i
		end



feature {NONE}
	parse_factor : STRING
		Local
			i : INTEGER
		do
			if s.item(1) = '('
			then i := parse_constant.to_integer
			else
				if s.item(1) = '('
				then s.remove(1)
					 i := parse_expression.to_integer
					 if s.item(1) = ')'
					 then s.remove(1)

					 end

				end

			end
			Result := i.out
		end


feature {NONE}
	parse_constant : STRING
		Local
			i : STRING
		do
			i := ""
			if is_digit_wo_zero
			then
			from
			until
				is_digi = False
			loop
				i := i + s.item(1).out
				s.remove(1)
			end

			end
			Result := i
		end


feature {NONE}
	is_digi : BOOLEAN
		Local
			i : BOOLEAN
		do
			if is_digit_wo_zero or s.has ('0')
			then i := True
			else
				i := False
			end
			Result := i
		end

feature {NONE}
	is_digit_wo_zero : BOOLEAN
		Local
			b : BOOLEAN
			i : INTEGER
		do
			b := False
			from
				i := 1
			until
				i = s.capacity
			loop
				if s.item (i) = '1' or s.item (i) = '2' or s.item (i) = '3' or s.item (i) = '4' or s.item (i) = '5' or s.item (i) = '6'
					or s.item (i) = '7' or s.item (i) = '8' or s.item (i) = '9'
				then b := True
				else
					b := False
				end
			end

		end



feature {NONE}
	empty_brackets : BOOLEAN
		Local
			b : BOOLEAN
			i : INTEGER
		do
			b := False
			from
				i := 1
			until
				i = s.capacity
			loop
				if s.item (i) = '(' and s.item (i+1) = ')'
				then b := True
				end
				i := i+1
			end
			Result := b
		end


feature {NONE}
	no_number_before_after_operator : BOOLEAN
		Local
			b : BOOLEAN
			i : INTEGER
		do
			b := False
			from
				i := 2
			until
				i = s.capacity
			loop
				if (s.item (i) = '+' or s.item (i) = '*')
				and (not (s.item (i+1).is_digit or s.item (i+1) = '(')
				or not (s.item (i-1).is_digit or s.item (i-1) = ')'))
				then b := True
				end
				i := i+1
			end
			Result := b
		end

feature {NONE}
	not_allowed_sign : BOOLEAN
		Local
			b : BOOLEAN
			i : INTEGER
		do
			b := False
			from
				i := 1
			until
				i = s.capacity
			loop
				if not (s.item(i).is_digit or s.item (i) = '=' or s.item (i) = '+' or s.item (i) = '*' or s.item (i) = '(' or s.item (i) = ')')
				then b := True

				end
				i := i+1
			end
			Result := b
		end
end
