#!/usr/bin/ruby

def sum(array) 
	if(array.length == 0) 
		return 0
	else
		counter = 0
		for i in array
			counter = i + counter
		end	
	return counter
	end
end

def max_2_sum(array)
	if(array.length == 0)
		return 0
	end
	if(array.length == 1)
		return array[0]
	end
	array.sort()
	return array[array.length - 1] + array[array.length - 2]
end

def sum_to_n?(array, n)
	if(array.length == 0 && n == 0)
		return TRUE
	end
	for i in array
		for j in array[i + 1 .. array.length]
			if((i + j) == n)
				return TRUE
			end
		end
	end
	return FALSE
end

puts sum([])

puts sum([1, 2, 3, 4, 5])

puts max_2_sum([])

puts max_2_sum([991])

puts max_2_sum([1, 2, 3, 4, 5])

sum_to_n?([], 0)

sum_to_n?([1, 2, 3, 4, 5], 7)

sum_to_n?([1, 2, 3, 4, 5], 2)

