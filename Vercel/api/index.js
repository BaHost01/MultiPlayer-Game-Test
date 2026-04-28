const express = require('express');
const app = express();

app.use(express.json());

// Handshake
app.post('/', (req, res) => {
  console.log('Handshake received');
  res.status(200).json({ status: 'connected', message: 'Welcome to the Multiplayer Server' });
});

// Player Packet
app.post('/Packet', (req, res) => {
  const { user, vector } = req.body;
  console.log(`Packet from ${user}:`, vector);
  // In a real app, you'd broadcast this or save it to a database
  res.status(200).json({ status: 'ok', received: { user, vector } });
});

// Ban
app.post('/Ban', (req, res) => {
  const { user } = req.body;
  console.log(`Ban requested for ${user}`);
  res.status(200).json({ status: 'banned', user });
});

module.exports = app;
