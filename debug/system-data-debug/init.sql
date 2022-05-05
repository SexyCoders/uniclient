CREATE DATABASE IF NOT EXISTS debug_db;

USE debug_db;

CREATE TABLE IF NOT EXISTS customers (
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  company VARCHAR(255) NOT NULL,
  name VARCHAR(255),
  lname VARCHAR(255),
  phone INT,
  email VARCHAR(255),
  address VARCHAR(255),
  zip VARCHAR(255),
  tin VARCHAR(255),
  notes VARCHAR(255)
);

INSERT INTO customers (id, company) VALUES (1, 'Test Company');