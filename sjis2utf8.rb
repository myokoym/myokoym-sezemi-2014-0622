#!/usr/bin/env ruby

require "fileutils"

FILES = [
  "README.md",
  "recipe-data1.txt",
  "recipe-data2.txt",
  "recipe-data3.txt",
  "recipe-data4.txt",
  "recipe/recipe.c",
  "recipe-csv/recipe-csv.c",
  "lib/user.c",
  "lib/recipe.c",
]

def sjis2utf8(text)
  text.encode(Encoding::UTF_8, Encoding::Windows_31J)
end

FILES.each do |filename|
  filename_tmp = "#{filename}.tmp"
  File.open(filename) do |input_file|
    File.open(filename_tmp, "w") do |output_file|
      input_file.each_line do |sjis_line|
        utf8_line = sjis2utf8(sjis_line)
        output_file.puts(utf8_line)
      end
    end
  end
  FileUtils.mv(filename_tmp, filename)
end
