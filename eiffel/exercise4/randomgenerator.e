note
	description: "Summary description for {RANDOMGENERATOR}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	RANDOMGENERATOR

create
	make

feature {NONE} -- Initialization

	make
			-- Initialization for `Current'.
		do
			create ra.make
			create ra_string.make_empty
			create content.make_empty
			create math
		end

feature --Access
	ra : RANDOM
	-- Random-Object
	ra_int : INTEGER
	-- variable for random int values
	ra_real : DOUBLE
	--
	ra_string : STRING
	content : STRING
	ra_index : INTEGER
	ra_counter : INTEGER
	loop_value : INTEGER
	math : DOUBLE_MATH
	mal : DOUBLE
	divisor : INTEGER

feature -- INT

	get_ra_int(min : INTEGER ; max : INTEGER) : INTEGER
	do
		ra_int := ra.next_random (max)
		Result := ra_int

	end

feature  -- Double

	get_ra_double(min : INTEGER ; max : INTEGER) : DOUBLE
	do
		Result := 0.5
	end

feature -- STRING

	get_ra_string(min : INTEGER ; max : INTEGER) : STRING
	do
		ra_string := ""
		content := "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

		ra_counter := ra.next_random (42)
		-- Why 42 ? Its the aswer to everything (random value)

		from
			loop_value := 0
		until
			loop_value = ra_counter
		loop
			ra_index := get_ra_int(0, content.count)
			ra_string := ra_string + content.item (ra_index).out
			-- out makes it into a string
			loop_value := loop_value + 1
		end

		Result := ra_string
	end

end
