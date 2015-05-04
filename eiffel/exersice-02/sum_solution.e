note
	description: "Summary description for {SUM_SOLUTION}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	SUM_SOLUTION

inherit
	SOLUTION

feature --Access

 	sum : INTEGER
 	-- the sum of all nodes in a given tree


feature --Getter for sum

	get_soultion_value : INTEGER
	do
		Result := sum
	end


end
