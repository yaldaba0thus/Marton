max_value <- (numbers: list[int]) -> int {
	let max <- numbers[0];

	for item in numbers {
		if item > max {
			max <- item;
		}
	}

	max
}

sum_values <- (numbers: list[int]) -> int {
	let total <- 0;

	for item in numbers {
		total <- total + item;
	}

	total
}

main <- () -> {
	let numbers: array[int : 8] <- [1, 3, 5, 7, 9, 2, 4, 6];

	let max_num <- max_value(numbers);
	let sum_num <- sum_values(numbers);

	if max_num > 5 {
		print("Максимум больше 5: " + max_num);
	} else {
		print("Максимум меньше или равен 5: " + max_num);
	}

	if sum_num > 30 {
		print("Сумма чисел больше 30: " + sum_num);
	} else {
		print("Сумма чисел меньше или равна 30: " + sum_num);
	}

	let range_sum <- 0;

	for 0 -> x in (0..6] {
		range_sum <- range_sum + x;
	}

	print("Сумма чисел от 0 до 5: " + range_sum);
}

main();