#!/usr/bin/env python3
""" Generate header file for FOO errors."""

import argparse


def generate_header(input, output):
    input_text = ""

    with open(input, "r") as file:
        input_text = file.readlines()

    output_lines = []

    for line in input_text:
        name = line.strip().split(":")[0]
        value = len(output_lines)

        output_lines.append(f"\t{name} = {value},")

    enum_name = output_lines[0].split("_")[0].strip()
    enum_text = "\n".join(output_lines)
    output_text = f"""#pragma once

enum {enum_name}_error {{
{enum_text}
}};"""

    with open(output, "w") as file:
        file.write(output_text)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("input", help="The input file.")
    parser.add_argument("output", help="The output file.")

    args = parser.parse_args()

    generate_header(args.input, args.output)
