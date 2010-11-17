
class Makefile
  
  def initialize(extension_name)
    @c_library_header_path = File.expand_path(File.join(File.dirname(__FILE__), '..', '..', '..', 'source')) 
    @c_header_flag = %{-I #{@c_library_header_path}}
    @objects_to_link = Dir["*.o", "#{@c_library_header_path}/*/*.o"].join(' ')

    with_cflags(@c_header_flag) do
      with_ldflags(@objects_to_link) do
        create_makefile(extension_name)
      end
    end
    
  end
  
end