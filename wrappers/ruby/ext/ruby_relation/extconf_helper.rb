
class Makefile
  RELATION_HEADER_PATH = File.expand_path(File.join(File.dirname(__FILE__), '..', '..', '..', '..', 'source'))
  RELATION_HEADER_FLAG = "-I #{RELATION_HEADER_PATH}"

  OBJECTS_TO_LINK = Dir["*.o", "#{RELATION_HEADER_PATH}/*.o", "#{RELATION_HEADER_PATH}/*/*.o"].join(' ')
  
  def initialize(extension_name)
    with_cflags(RELATION_HEADER_FLAG) do
      with_ldflags(OBJECTS_TO_LINK) do
        create_makefile(extension_name)
      end
    end    
  end
  
end