
def minimumPlatforms(arrival, departure):
    arrival.sort()
    departure.sort()
    n = len(arrival)
    plat_needed, result = 1, 1
    i, j = 1, 0
    while i < n and j < n:
        if arrival[i] <= departure[j]:
            plat_needed += 1
            i += 1
        else:
            plat_needed -= 1
            j += 1
        result = max(result, plat_needed)
    return result
