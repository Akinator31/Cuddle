# Cuddle

A lightweight C implementation inspired by Python's Pandas library for data manipulation and analysis.

## Overview

Cuddle is a powerful C library designed to handle data frames and provide similar functionality to Python's Pandas. It offers efficient data structures and operations for working with structured data.

### Key Features

- **Data Frame Operations**
  - Create and manipulate tabular data
  - Read/write CSV files
  - Dynamic type inference
  - Column-based storage

- **Basic Operations**
  - `df_head()` - View first N rows
  - `df_tail()` - View last N rows
  - `df_shape()` - Get dimensions
  - `df_info()` - Display structure info
  - `df_describe()` - Statistical summary

- **Data Manipulation**
  - Filtering rows
  - Sorting data
  - Type conversion
  - Applying functions
  - Group by operations

- **Memory Management**
  - Built-in garbage collector
  - Safe memory handling
  - Automatic cleanup

## Getting Started

### Build the Library

```bash
make              # Build the library
make debug        # Build with debug symbols
```

### Example Usage

```c
#include "dataframe.h"

int main(void) {
    // Read CSV file
    dataframe_t *df = df_read_csv("data.csv", ",");
    
    // Display first 5 rows
    dataframe_t *head = df_head(df, 5);
    df_dump(head);
    
    // Get basic information
    df_info(df);
    
    // Clean up
    df_free(df);
    df_free(head);
    return 0;
}
```

## Documentation

### Core Functions
- `df_read_csv()` - Read data from CSV file
- `df_write_csv()` - Write data to CSV file

### Data Analysis
- `df_filter()` - Filter rows based on conditions
- `df_sort()` - Sort data by column
- `df_groupby()` - Group data for aggregation
- `df_apply()` - Apply function to columns

### Utilities
- `df_get_value()` - Get single value
- `df_get_values()` - Get column values
- `df_dump()` - Display data frame content

## Contributing

Feel free to contribute by:
1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request
