let hello_worlds n =
    for i = 1 to n do
        print_string("Hello World\n");
    done

let () =
    let a = read_int() in
    hello_worlds(a);
