#!/usr/bin/python3
'''Recursive function that queries the Reddit API and returns a list
containing the titles of all hot articles for a given subreddit'''

import requests


def count_words(subreddit, wlist, after="", counting={}):
        """Recursive function that queries the Reddit API and returns a list
        containing the titles of all hot articles for a given subreddit"""
        if after is None:
            return []
        url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
        headers = {'User-Agent':
                   'Mozilla/5.0 (Windows NT 10.0; Win64; x64)\
                   AppleWebKit/537.36 (KHTML, like Gecko)\
                   Chrome/70.0.3538.77 Safari/537.36'}
        if after:
            url += '?after={}'.format(after)
        r = requests.get(url, headers=headers, allow_redirects=False)
        if str(r) != '<Response [200]>':
            return None
        data = r.json().get('data')
        after = data.get('after')
        children_list = data.get('children')
        for child in children_list:
            title = child.get('data').get('title')
            for word in wlist:
                ocurrences = title.lower().split().count(word.lower())
                if ocurrences > 0:
                    if word in counting:
                        counting[word] += ocurrences
                    else:
                        counting[word] = ocurrences
        if after is not None:
            return count_words(subreddit, wlist, after, counting)
        else:
            if not len(counting) > 0:
                return
            iterator = sorted(counting.items(),
                              key=lambda kv: (-kv[1], kv[0]))
            for key, value in iterator:
                print('{}: {}'.format(key.lower(), value))
