class
	APPLICATION

--APPLICATION inherits ARGUMENTS
inherit
	ARGUMENTS

-- start with make
create
	make

--private attributes
feature {NONE}
	p : PARSER

	--The main
	--Checks how many arguments are given and work with them. There are Exception messages if
	-- the number of arguments are > 2 or the content for the arguments are wrong
	make (arguments : ARRAY [STRING])
		local
			file : PLAIN_TEXT_FILE -- initialization the file
			s : STRING
		do
			s := ""
			create p.make -- create a new parser
			arguments.remove_head (1) -- delete the header (the path)
			if arguments.capacity = 1
			then p.parser (arguments.item (1)) -- if there are only one argument, it is a equation without a file and calculate it direktly
			else
				if arguments.capacity = 2
				then if arguments.item (1).is_equal ("file") or arguments.item (1).is_equal ("File") or arguments.item (1).is_equal ("FILE")
					 then create file.make_with_name (arguments.item (2))							-- if there are two arguments and the first argument is file then a file will be created
						if file.access_exists														-- if a file access exist
						then if file.is_empty														-- and the file is empty -> Exception message
							 then io.put_string ("File '" + arguments.item (2) + "' is empty.")
						 	 else
								create file.make_open_read (arguments.item (2))						-- open the read file on the second argument
								from																-- they read with using a loop until the end of the line and parse the read string
								until
									file.end_of_file
								loop
									file.read_line
									s.make_from_string (file.last_string)
									p.parser (s)
									if not file.end_of_file											-- if its not the end of the file
									then io.new_line												-- they read the next line of the file
									end
								end
								file.close															-- file will be closed
							end
						else
							io.put_string ("File '" + arguments.item (2) + "' doesn't exist. Please check the given spelling of your path")
						end
					else
						io.put_string ("File have to be the first argument but it's: " + arguments.item (1))
					end
				else
					io.put_string ("Only one ore two parameters are allowed.")
				end
			end
		end

end
