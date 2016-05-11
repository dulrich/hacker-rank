let rec read_lines () =
    try let line = read_line () in
        int_of_string (line) :: read_lines()
    with
        End_of_file -> []

let f n arr =
    let rec prepend list e n =
        if n = 0 then list
        else prepend (e :: list) e (n - 1) in
    List.concat (List.map (fun x -> prepend [] x n) arr);;
    

let () =
    let n::arr = read_lines() in
    let ans = f n arr in
    List.iter (fun x -> print_int x; print_newline ()) ans;;
