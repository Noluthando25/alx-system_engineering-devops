#!/usr/bin/python3
"""Module to query the Reddit API and return number of subscribers."""
import requests


def number_of_subscribers(subreddit):
    """
    Query the Reddit API and return the number of subscribers
    for a given subreddit.

    Args:
        subreddit (str): The name of the subreddit.

    Returns:
        int: The number of subscribers. Returns 0 for invalid subreddits.
    """
    url = "https://www.reddit.com/r/{}/about.json".format(subreddit)
    headers = {
        "User-Agent": "linux:0-subs:v1.0.0 (by /u/your_reddit_username)"
    }

    try:
        response = requests.get(url, headers=headers, allow_redirects=False)
        if response.status_code == 200:
            return response.json()['data']['subscribers']
        else:
            return 0
    except requests.RequestException:
        return 0


if __name__ == '__main__':
    import sys
    if len(sys.argv) < 2:
        print("Please pass an argument for the subreddit to search.")
    else:
        print("{:d}".format(number_of_subscribers(sys.argv[1])))

