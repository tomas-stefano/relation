['relation_table'].each do |file|
  require "relation/#{file}"
end