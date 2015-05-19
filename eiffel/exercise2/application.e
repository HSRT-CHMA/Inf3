note
	description : "uebungsaufgabe application root class"
	date        : "$Date$"
	revision    : "$Revision$"

class
	APPLICATION

inherit
	ARGUMENTS

create
	make

feature {NONE} -- Initialization

	-- "Main"-Method receives a String-array with Arguments; defined in
	-- Execution -> Execution Parameters
	make(arguments : ARRAY[STRING])
		Local
			i : INTEGER
		do
			print ("Hello Eiffel World!%N")
			create my_parser.make
			from
				i := arguments.lower + 1			-- By starting at 1, the programm-name is avoided
			until
				i > arguments.upper
			loop
				my_parser.line_parse(arguments.item (i))
				print("%N")
				i := i + 1
			end
		end

feature -- Access

	my_parser : PARSER


end
