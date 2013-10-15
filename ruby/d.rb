def args(code)
	one, two = 1, 2
	code.call(one, two)
end

args(Proc.new { |a, b, c| puts "Give me a #{a} and a #{b} and a #{c.class}"})

args(lambda { |a, b, c| puts "Give me a #{a} and a #{b} and a #{c.class}")
