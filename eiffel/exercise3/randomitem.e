note
	description: "Summary description for {RANDOMITEM}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	RANDOMITEM
	-- Class creates random items for generic testing

feature

	r : RANDOM

feature
	randomInt : INTEGER
	do
		Result:= random_sequence.item
	end

feature
	randomString : STRING
	do

	end

feature
	randomDouble : DOUBLE
	do

	end
end
