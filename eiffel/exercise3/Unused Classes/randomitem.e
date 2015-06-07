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
	Local
		random_number : INTEGER
	do
		create r.make
		random_number:= r.next_random(100)
		Result:= random_number
	end

feature
	randomString : STRING
	Local
	stringItem = STRING["Alpha", "Johnny", "afrtegt","dfg", "354rfd", "last","fgd883", "rock", "peter","g4rwf", "movie", "34","fridge",
     "hgadi034r", "vnhwe678sd", "Tom", "grf4","gf4356fg", "gh563gftd", "57fgfghed3","blah", "blahblah", "45qfg435","sgr33354345s", "kidding",
     "97","potato", "tomato", "fg5zhds46d"]
	do
		Result:=r.stringItem[r.next_random(stringItem.count)]
	end

feature
	randomFloat : REAL
	Local
		random_float : REAL
	do
		create r.make
		random_float:= r.next_random(100).real_item
	end
end
