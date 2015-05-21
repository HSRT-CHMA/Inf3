--Main class (root) that will get arguments and creates a parser object.
class
	APPLICATION

--Inherits ARGUMENTS to get acces to the passed arguments.
inherit

	ARGUMENTS

--The routine to start is make.
create
	make

--Private attributes and routines.
feature {NONE}

	--The PARSER object.
	p : PARSER

	--The main routine.
	--Checks how many arguments are given and prints a helpful error message if
	--the amount of arguments is wrong or the given arguments are wrong.
	make (arguments : ARRAY [STRING])
		local
			input_file : PLAIN_TEXT_FILE
			s : STRING
		do
			s := ""
			create p.make
			arguments.remove_head(1)
			if arguments.capacity = 1 then
				p.parser(arguments.item(1))
			else
				if arguments.capacity = 2 then
					if arguments.item (1).is_equal ("file") then
						create input_file.make_with_name (arguments.item (2))
						if input_file.access_exists then
							if input_file.is_empty then
								io.put_string ("File '" + arguments.item (2) + "' is empty.")
							else
								create input_file.make_open_read (arguments.item (2))
								from
								until
									input_file.end_of_file
								loop
									input_file.read_line
									s.make_from_string (input_file.last_string)
									p.parser (s)
									if not input_file.end_of_file then
										io.new_line
									end
								end
								input_file.close
							end
						else
							io.put_string ("Error: File '" + arguments.item (2) + "' does not exist.")
						end
					else
						io.put_string ("Error: Expected 'file' as first paramter but got '" + arguments.item (1) + "'")
					end
				else
					io.put_string ("Error: Only one ore two parameters are allowed. You gave " + arguments.capacity.out + " parameters.")
				end
			end
		end

end
