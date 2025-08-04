from collections import defaultdict

def max_profit(t, test_cases):
    results = []
    
    for n, k, bottles in test_cases:
        # Group prices by brand
        brand_prices = defaultdict(list)
        for brand, price in bottles:
            brand_prices[brand].append(price)
        
        # Calculate max earnings for each brand
        brand_values = []
        for prices in brand_prices.values():
            prices.sort(reverse=True)  # Sort each brand's prices in descending order
            brand_value = sum(prices[:min(len(prices), n)])  # Take the top prices up to `n` shelves
            brand_values.append(brand_value)
        
        # Get the top `n` brand values
        brand_values.sort(reverse=True)
        max_profit = sum(brand_values[:n])
        
        results.append(max_profit)
    
    return results

# Example usage
t = 4
test_cases = [
    (3, 3, [(2, 6), (2, 7), (1, 15)]),
    (1, 3, [(2, 6), (2, 7), (1, 15)]),
    (6, 2, [(1, 7), (2, 5)]),
    (190000, 1, [(1, 1000)])
]

output = max_profit(t, test_cases)
for result in output:
    print(result)
