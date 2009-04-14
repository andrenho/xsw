File.new('rgb.txt').each_line do |line|
	v = line.split
	puts "\telse if(strcmp(desc, \"#{v[3]}\") == 0)"
	puts "\t{"
	puts "\t\tc[0] = #{v[0]};"
	puts "\t\tc[1] = #{v[1]};"
	puts "\t\tc[2] = #{v[2]};"
	puts "\t}"
end
