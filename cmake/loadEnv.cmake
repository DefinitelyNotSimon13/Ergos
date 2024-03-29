function(load_env file)
    file(STRINGS ${file} lines)
    foreach(line ${lines})
        if(NOT "${line}" MATCHES "^\\s*#")
            string(REPLACE " " "" line ${line})
            string(REPLACE "=" ";" line ${line})
            list(GET line 0 var)
            list(REMOVE_AT line 0)
            list(JOIN line "=" val)
            message(ENV{${var}} ${val})
            set(ENV{${var}} ${val})
        endif()
    endforeach()
endfunction()