def main():
    #simply opening file and perfrom read and print
    driver_handle = open('/proc/firstmod')
    message_from_kernel_space = driver_handle.readline()
    print(message_from_kernel_space)
    driver_handle.close()
    return

main()