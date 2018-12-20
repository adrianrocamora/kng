input = [	29
			5
			12
			7
			4
			2
			22
			13
			27
			25
			6
			24
			30
			8
			3
			10
			18
			29
			23
			20
			26
			16
			21
			14
			19
			11
			17
			15
			28
			9];

for i = 2:input(1)+1
	res = (3+sqrt(5))^input(i);
	%res = mod(res,1000);
	res = floor(res);
	disp(sprintf('%03d', res))
end

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
