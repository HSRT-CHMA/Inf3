note
	description: "Summary description for {MAX_SOLUTION}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	MAX_SOLUTION

create
	make

feature {NONE} -- Initialization

	make
			-- Initialization for `Current'.
		do

		end


feature --Access

	max : INTEGER
	-- The max-value found in the given tree

feature -- Getter for max,returns max

	get_solution_value : INTEGER
	do
		Result := max
	end

end
