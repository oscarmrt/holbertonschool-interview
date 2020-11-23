#!/usr/bin/node

const request = require('request');

const apiurl = 'https://swapi.dev/api/films/' + process.argv.slice(2) + '/';

request(apiurl, async function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const characters = JSON.parse(body).characters;
    for (const url of characters) {
      const res = await new Promise((resolve, reject) => {
        request(url, (error, res, body2) => {
          if (error) {
            reject(error);
          } else {
            resolve(JSON.parse(body2).name);
          }
        });
      });
      console.log(res);
    }
  }
});
