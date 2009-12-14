-- phpMyAdmin SQL Dump
-- version 3.1.2deb1ubuntu0.2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 03, 2009 at 07:26 PM
-- Server version: 5.0.75
-- PHP Version: 5.2.6-3ubuntu4.2

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `battleship`
--

-- --------------------------------------------------------

--
-- Table structure for table `6x6`
--

CREATE TABLE IF NOT EXISTS `6x6` (
  `board` varchar(36) NOT NULL,
  `h` varchar(6) NOT NULL,
  `v` varchar(6) NOT NULL,
  PRIMARY KEY  (`board`),
  KEY `h` (`h`,`v`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `8x8`
--

CREATE TABLE IF NOT EXISTS `8x8` (
  `board` varchar(64) NOT NULL,
  `h` varchar(8) NOT NULL,
  `v` varchar(8) NOT NULL,
  PRIMARY KEY  (`board`),
  KEY `h` (`h`,`v`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `10x10`
--

CREATE TABLE IF NOT EXISTS `10x10` (
  `board` varchar(100) NOT NULL,
  `h` varchar(10) NOT NULL,
  `v` varchar(10) NOT NULL,
  PRIMARY KEY  (`board`),
  KEY `h` (`h`,`v`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
