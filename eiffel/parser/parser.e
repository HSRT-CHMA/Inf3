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
			-- Initialization for `Current'.
		do
			create s.make_empty
		end

feature -- public
	parser(input : STRING)
		do
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
							if s.occurrences ('(') > 0 and not right_order_of_brackets
							then io.put_string("wrong order of brackets")
								else
									if empty_brackets
									then io.put_string ("No content between brackets")
									else
										if no_digit_before_or_after_operator
										then io.put_string ("No number before and after operator")
										else
											if not (s.has(is_digit(s)) and s.has ('=') and s.has ('+') and s.has ('*') and s.has ('(') and s.has (')'))
											then io.put_string ("Character is not allowed")
											else
												if s.occurrences ('=') > 1
												then io.put_string ("Only one '=' is allowed")
												else
													io.put_string("The result is: " + parse_equation(s))
												end

											end

										end

									end
							end

						end

					end

				end

			end
		end




feature {NONE}
	parse_equation(input : STRING) : STRING
		Local
			i : STRING
			left : INTEGER
			right : INTEGER
		do
			i := ""
			if s.occurrences ('=') = 0
			then i := parse_expression(input)
			else
				if s.occurrences ('=') = 1
				then left := parse_expression(input).to_integer
					 s.remove(1)
					 right := parse_expression(input).to_integer
					 i := (left = right).out

				end

			end
			Result := i
		end


feature {NONE}
	parse_expression(input : STRING) : STRING
		Local
			i : STRING
			left : INTEGER
			right : INTEGER
		do
			i := ""
			if s.occurrences('+') = 0
			then i := parse_term(input)
			else
				if s.occurrences ('+') > 0
				then left := parse_term(input).to_integer
				i := left.out
				from
				until
					s.occurrences ('+') = 0 or s.item(1) /= '+'
				loop
					s.remove(1)
					right := parse_term(input).to_integer
					i := (i.to_integer + right).out
				end

				end
			end
			Result := i
		end



feature {NONE}
	parse_term(input : STRING) : STRING
		Local
			i : STRING
			left : INTEGER
			right : INTEGER
		do
			if s.occurrences ('*') = 0
			then i := parse_factor(input)
			else
				i := ""
				if s.occurrences ('*') > 0
				then left := parse_factor(input).to_integer
					 i := left.out
					 from
					 until
					 	s.occurrences ('*') = 0 or s.item(1) /= '*'
					 loop
					 	s.remove(1)
					 	right := parse_factor(input).to_integer
					 	i := (i.to_integer * right).out
					 end

				end

			end
			Result := i
		end



feature {NONE}
	parse_factor(input : STRING) : STRING
		Local
			i : INTEGER
		do
			if s.item(1) = '('
			then i := parse_constant(input).to_integer
			else
				if s.item(1) = '('
				then s.remove(1)
					 i := parse_expression(input).to_integer
					 if s.item(1) = ')'
					 then s.remove(1)

					 end

				end

			end
			Result := i.out
		end


feature {NONE}
	parse_constant(input : STRING) : STRING
		Local
			i : STRING
		do
			i := ""
			if is_digit_wo_zero(input)
			then from
			until
				is_digit(input) = False
			loop
				i := i + s.item(1).out
				s.remove(1)
			end

			end
			Result := i
		end


feature {NONE}
	is_digit(input : STRING) : BOOLEAN
		Local
			i : BOOLEAN
		do
			if s.is_empty = False
			then i := s.item(1).is_digit
			else
				i := False
			end
			Result := i
		end

feature {NONE}
	is_digit_wo_zero(input : STRING) : BOOLEAN
		Local
			i : BOOLEAN
		do
			if s.is_empty = False
			then i := s.item(1).is_digit and s.item(1).out.to_integer /= 0
			else
				i := False
			end
			Result := i
		end
	end

