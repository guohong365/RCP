#include  "Quotation.h"
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Parser.h>
namespace rcp {

	void IQuotation::dump(std::ostream& stream, IQuotation * p)
	{
		stream
			///合约代码
			<< "instrument Id:" << p->instrumentId() << std::endl
			///交易日
			<< "trade day:" << p->tradingDay() << std::endl
			///交易所代码
			<< "exchanged id:" << p->exchangeId() << std::endl
			///合约在交易所的代码
			<< "exchanged instrument id:" << p->exchangeInstrumentId() << std::endl
			///最新价
			<< "last price:" << p->lastPrice() << std::endl
			///上次结算价
			<< "prev settlement price:" << p->prevSettlementPrice() << std::endl
			///昨收盘
			<< "prev close price:" << p->prevClosePrice() << std::endl
			///昨持仓量
			<< "prev open interest:" << p->prevOpenInterest() << std::endl
			///今开盘
			<< "open price:" << p->openPrice() << std::endl
			///最高价
			<< "higest price:" << p->highestPrice() << std::endl
			///最低价
			<< "lowest price:" << p->lowestPrice() << std::endl
			///数量
			<< "volume:" << p->volume() << std::endl
			///成交金额
			<< "turnover:" << p->turnover() << std::endl
			///持仓量
			<< "open interest:" << p->openInterest() << std::endl
			///今收盘
			<< "close price:" << p->closePrice() << std::endl
			///本次结算价
			<< "settlement price:" << p->settlementPrice() << std::endl
			///涨停板价
			<< "upper limit price:" << p->upperLimitPrice() << std::endl
			///跌停板价
			<< "lower limit price:" << p->lowerLimitPrice() << std::endl
			///昨虚实度
			<< "prev delta:" << p->prevDelta() << std::endl
			///今虚实度
			<< "current delta:" << p->currentDelta() << std::endl
			///最后修改时间
			<< "update time:" << p->updateTime() << std::endl
			///最后修改毫秒
			<< "update millisecond:" << p->updateMillisecond() << std::endl
			///申买价一
			<< "bid price 1:" << p->bidPrice1() << std::endl
			///申买量一
			<< "bid volume 1:" << p->bidVolume1() << std::endl
			///申卖价一
			<< "ask price 1:" << p->askPrice1() << std::endl
			///申卖量一
			<< "ask volume 1:" << p->askVolume1() << std::endl
			///申买价2
			<< "bid price 2:" << p->bidPrice2() << std::endl
			///申买量2
			<< "bid volume 2:" << p->bidVolume2() << std::endl
			///申卖价2
			<< "ask price 2:" << p->askPrice2() << std::endl
			///申卖量2
			<< "ask volume 2:" << p->askVolume2() << std::endl
			///申买价3
			<< "bid price 3:" << p->bidPrice3() << std::endl
			///申买量3
			<< "bid volume 3:" << p->bidVolume3() << std::endl
			///申卖价3
			<< "ask price 3:" << p->askPrice3() << std::endl
			///申卖量3
			<< "ask volume 3:" << p->askVolume3() << std::endl
			///申买价4
			<< "bid price 4:" << p->bidPrice4() << std::endl
			///申买量4
			<< "bid volume 4:" << p->bidVolume4() << std::endl
			///申卖价4
			<< "ask price 4:" << p->askPrice4() << std::endl
			///申卖量4
			<< "ask volume 4:" << p->askVolume4() << std::endl
			///申买价5
			<< "bid price 5:" << p->bidPrice5() << std::endl
			///申买量5
			<< "bid volume 5:" << p->bidVolume5() << std::endl
			///申卖价5
			<< "ask price 5:" << p->askPrice5() << std::endl
			///申卖量5
			<< "ask volume 5:" << p->askVolume5() << std::endl
			///当日均价
			<< "average price:" << p->averagePrice() << std::endl
			///业务日期
			<< "action day:" << p->actionDay() << std::endl;
	}

	AbstractQuotation::~AbstractQuotation() = default;

	const std::string& AbstractQuotation::instrumentId() const
	{
		return _instrumentId;
	}

	const std::string& AbstractQuotation::tradingDay() const
	{
		return _tradingDay;
	}

	const std::string& AbstractQuotation::exchangeId() const
	{
		return _exchangeId;
	}

	const std::string& AbstractQuotation::exchangeInstrumentId() const
	{
		return _exchangeInstrumentId;
	}

	double  AbstractQuotation::lastPrice() const
	{
		return _lastPrice;
	}

	double  AbstractQuotation::prevSettlementPrice() const
	{
		return _prevSettlementPrice;
	}

	double  AbstractQuotation::prevClosePrice() const
	{
		return _prevClosePrice;
	}

	double  AbstractQuotation::prevOpenInterest() const
	{
		return _prevOpenInterest;
	}

	double  AbstractQuotation::openPrice() const
	{
		return _openPrice;
	}

	double  AbstractQuotation::highestPrice() const
	{
		return _highestPrice;
	}

	double  AbstractQuotation::lowestPrice() const
	{
		return _lowestPrice;
	}

	int  AbstractQuotation::volume() const
	{
		return _volume;
	}

	double  AbstractQuotation::turnover() const
	{
		return _turnover;
	}

	double  AbstractQuotation::openInterest() const
	{
		return _openInterest;
	}

	double  AbstractQuotation::closePrice() const
	{
		return _closePrice;
	}

	double  AbstractQuotation::settlementPrice() const
	{
		return _settlementPrice;
	}

	double  AbstractQuotation::upperLimitPrice() const
	{
		return _upperLimitPrice;
	}

	double  AbstractQuotation::lowerLimitPrice() const
	{
		return _lowerLimitPrice;
	}

	double  AbstractQuotation::prevDelta() const
	{
		return _prevDelta;
	}

	double  AbstractQuotation::currentDelta() const
	{
		return _currentDelta;
	}

	const std::string& AbstractQuotation::updateTime() const
	{
		return _updateTime;
	}

	int AbstractQuotation::updateMillisecond() const
	{
		return _updateMillisecond;
	}

	double AbstractQuotation::bidPrice1() const
	{
		return _bidPrice1;
	}

	int  AbstractQuotation::bidVolume1() const
	{
		return _bidVolume1;
	}

	double  AbstractQuotation::askPrice1() const
	{
		return _askPrice1;
	}

	int AbstractQuotation::askVolume1() const
	{
		return _askVolume1;
	}

	double AbstractQuotation::bidPrice2() const
	{
		return _bidPrice2;
	}

	int AbstractQuotation::bidVolume2() const
	{
		return _bidVolume2;
	}

	double  AbstractQuotation::askPrice2() const
	{
		return _askPrice2;
	}

	int AbstractQuotation::askVolume2() const
	{
		return _askVolume2;
	}

	double AbstractQuotation::bidPrice3() const
	{
		return _bidPrice3;
	}

	int  AbstractQuotation::bidVolume3() const
	{
		return _bidVolume3;
	}

	double  AbstractQuotation::askPrice3() const
	{
		return _askPrice3;
	}

	int AbstractQuotation::askVolume3() const
	{
		return _askVolume3;
	}

	double AbstractQuotation::bidPrice4() const
	{
		return _bidPrice4;
	}

	int  AbstractQuotation::bidVolume4() const
	{
		return _bidVolume4;
	}

	double AbstractQuotation::askPrice4() const
	{
		return _askPrice4;
	}

	int  AbstractQuotation::askVolume4() const
	{
		return _askVolume4;
	}

	double AbstractQuotation::bidPrice5() const
	{
		return _bidPrice5;
	}

	int  AbstractQuotation::bidVolume5() const
	{
		return _bidVolume5;
	}

	double AbstractQuotation::askPrice5() const
	{
		return _askPrice5;
	}

	int AbstractQuotation::askVolume5() const
	{
		return _askVolume5;
	}

	double AbstractQuotation::averagePrice() const
	{
		return _averagePrice;
	}

	const std::string& AbstractQuotation::actionDay() const
	{
		return _actionDay;
	}

	const std::string AbstractQuotation::toJsonString() const
	{
		Poco::JSON::Object object;
		object.set("instrumentId",instrumentId());
		object.set("tradingDay",tradingDay());
		object.set("exchangeId", exchangeId());
		object.set("exchangeInstrumentId", exchangeInstrumentId());
		object.set("lastPrice", lastPrice());
		object.set("prevSettlementPrice",prevSettlementPrice());
		object.set("prevClosePrice", prevClosePrice());
		object.set("prevOpenInterest", prevOpenInterest());
		object.set("openPrice", openPrice());
		object.set("highestPrice", highestPrice());
		object.set("lowestPrice", lowestPrice() );
		object.set("volume", volume());
		object.set("turnover", turnover());
		object.set("openInterest", openInterest());
		object.set("closePrice", closePrice());
		object.set("settlementPrice", settlementPrice());
		object.set("upperLimitPrice", upperLimitPrice());
		object.set("lowerLimitPrice", lowerLimitPrice());
		object.set("prevDelta", prevDelta());
		object.set("currentDelta", currentDelta());
		object.set("updateTime",updateTime());
		object.set("updateMillisecond", updateMillisecond());
		object.set("bidPrice1", bidPrice1());
		object.set("bidVolume1", bidVolume1());
		object.set("askPrice1", askPrice1());
		object.set("askVolume1", askVolume1());
		object.set("bidPrice2", bidPrice2());
		object.set("bidVolume2", bidVolume2());
		object.set("askPrice2", askPrice2());
		object.set("askVolume2", askVolume2());
		object.set("bidPrice3", bidPrice3());
		object.set("bidVolume3", bidVolume3());
		object.set("askPrice3", askPrice3());
		object.set("askVolume3", askVolume3());
		object.set("bidPrice4", bidPrice4());
		object.set("bidVolume4", bidVolume4());
		object.set("askPrice4", askPrice4());
		object.set("askVolume4", askVolume4());
		object.set("bidPrice5", bidPrice5());
		object.set("bidVolume5", bidVolume5());
		object.set("askPrice5", askPrice5());
		object.set("askVolume5", askVolume5());
		object.set("averagePrice", averagePrice());
		object.set("actionDay", actionDay());
		std::stringstream stream;
		object.stringify(stream);
		stream << std::endl;
		return stream.str();
	}

	void AbstractQuotation::fromJsonString(const std::string& jsonString)
	{
		Poco::JSON::Parser parser;
		Poco::Dynamic::Var result = parser.parse(jsonString);
		Poco::JSON::Object::Ptr pObject = result.extract<Poco::JSON::Object::Ptr>();

		instrumentId(pObject->getValue<std::string>("instrumentId"));
		tradingDay(pObject->getValue<std::string>("tradingDay"));
		exchangeId(pObject->getValue<std::string>("exchangeId"));
		exchangeInstrumentId(pObject->getValue<std::string>("exchangeInstrumentId"));
		lastPrice(pObject->getValue<double>("lastPrice"));
		prevSettlementPrice(pObject->getValue<double>("prevSettlementPrice"));
		prevClosePrice(pObject->getValue<double>("prevClosePrice"));
		prevOpenInterest(pObject->getValue<double>("prevOpenInterest"));
		openPrice(pObject->getValue<double>("openPrice"));
		highestPrice(pObject->getValue<double>("highestPrice"));
		lowestPrice(pObject->getValue<double>("lowestPrice"));
		volume(pObject->getValue<int>("volume"));
		turnover(pObject->getValue<double>("turnover"));
		openInterest(pObject->getValue<double>("openInterest"));
		closePrice(pObject->getValue<double>("closePrice"));
		settlementPrice(pObject->getValue<double>("settlementPrice"));
		upperLimitPrice(pObject->getValue<double>("upperLimitPrice"));
		lowerLimitPrice(pObject->getValue<double>("	lowerLimitPrice"));
		prevDelta(pObject->getValue<double>("prevDelta"));
		currentDelta(pObject->getValue<double>("currentDelta"));
		updateTime(pObject->getValue<std::string>("updateTime"));
		updateMillisecond(pObject->getValue<int>("updateMillisecond"));
		bidPrice1(pObject->getValue<double>("bidPrice1"));
		bidVolume1(pObject->getValue<int>("bidVolume1"));
		askPrice1(pObject->getValue<double>("askPrice1"));
		askVolume1(pObject->getValue<int>("askVolume1"));
		bidPrice2(pObject->getValue<double>("bidPrice2"));
		bidVolume2(pObject->getValue<int>("bidVolume2"));
		askPrice2(pObject->getValue<double>("askPrice2"));
		askVolume2(pObject->getValue<int>("askVolume2"));
		bidPrice3(pObject->getValue<double>("bidPrice3"));
		bidVolume3(pObject->getValue<int>("bidVolume3"));
		askPrice3(pObject->getValue<double>("askPrice3"));
		askVolume3(pObject->getValue<int>("askVolume3"));
		bidPrice4(pObject->getValue<double>("bidPrice4"));
		bidVolume4(pObject->getValue<int>("bidVolume4"));
		askPrice4(pObject->getValue<double>("askPrice4"));
		askVolume4(pObject->getValue<int>("askVolume4"));
		bidPrice5(pObject->getValue<double>("bidPrice5"));
		bidVolume5(pObject->getValue<int>("bidVolume5"));
		askPrice5(pObject->getValue<double>("askPrice5"));
		askVolume5(pObject->getValue<int>("askVolume5"));
		averagePrice(pObject->getValue<double>("averagePrice"));
		actionDay(pObject->getValue<std::string>("actionDay"));
	}

	AbstractQuotation::AbstractQuotation(const std::string& instrumentId, const std::string& tradingDay,
		const std::string& exchangeId, const std::string& exchangeInstrumentId,
		const double lastPrice,
		const double prevSettlementPrice, const double prevClosePrice,
		const double prevOpenInterest,
		const double openPrice, const double highestPrice, const double lowestPrice,
		const int volume,
		const double turnover, const double openInterest, const double closePrice,
		const double settlementPrice,
		const double upperLimitPrice, const double lowerLimitPrice, const double prevDelta,
		const double currentDelta,
		const std::string& updateTime,
		const int updateMillisecond, const double bidPrice1, const int bidVolume1,
		const double askPrice1,
		const int askVolume1, const double bidPrice2, const int bidVolume2,
		const double askPrice2, const int askVolume2,
		const double bidPrice3, const int bidVolume3, const double askPrice3,
		const int askVolume3, const double bidPrice4,
		const int bidVolume4, const double askPrice4, const int askVolume4,
		const double bidPrice5, const int bidVolume5,
		const double askPrice5, const int askVolume5,
		const double averagePrice, const std::string& actionDay):
	_instrumentId(instrumentId),
		_tradingDay(tradingDay),
		_exchangeId(exchangeId),
		_exchangeInstrumentId(exchangeInstrumentId),
		_lastPrice(lastPrice),
		_prevSettlementPrice(prevSettlementPrice),
		_prevClosePrice(prevClosePrice),
		_prevOpenInterest(prevOpenInterest),
		_openPrice(openPrice),
		_highestPrice(highestPrice),
		_lowestPrice(lowestPrice),
		_volume(volume),
		_turnover(turnover),
		_openInterest(openInterest),
		_closePrice(closePrice),
		_settlementPrice(settlementPrice),
		_upperLimitPrice(upperLimitPrice),
		_lowerLimitPrice(lowerLimitPrice),
		_prevDelta(prevDelta),
		_currentDelta(currentDelta),
		_updateTime(updateTime),
		_updateMillisecond(updateMillisecond),
		_bidPrice1(bidPrice1),
		_bidVolume1(bidVolume1),
		_askPrice1(askPrice1),
		_askVolume1(askVolume1),
		_bidPrice2(bidPrice2),
		_bidVolume2(bidVolume2),
		_askPrice2(askPrice2),
		_askVolume2(askVolume2),
		_bidPrice3(bidPrice3),
		_bidVolume3(bidVolume3),
		_askPrice3(askPrice3),
		_askVolume3(askVolume3),
		_bidPrice4(bidPrice4),
		_bidVolume4(bidVolume4),
		_askPrice4(askPrice4),
		_askVolume4(askVolume4),
		_bidPrice5(bidPrice5),
		_bidVolume5(bidVolume5),
		_askPrice5(askPrice5),
		_askVolume5(askVolume5),
		_averagePrice(averagePrice),
		_actionDay(actionDay)
	{
	}

	AbstractQuotation::AbstractQuotation() : _lastPrice(0), _prevSettlementPrice(0), _prevClosePrice(0),
		_prevOpenInterest(0), _openPrice(0), _highestPrice(0), _lowestPrice(0),
		_volume(0), _turnover(0), _openInterest(0), _closePrice(0), _settlementPrice(0),
		_upperLimitPrice(0), _lowerLimitPrice(0), _prevDelta(0), _currentDelta(0),
		_updateMillisecond(0), _bidPrice1(0), _bidVolume1(0), _askPrice1(0),
		_askVolume1(0), _bidPrice2(0), _bidVolume2(0), _askPrice2(0), _askVolume2(0),
		_bidPrice3(0), _bidVolume3(0), _askPrice3(0), _askVolume3(0), _bidPrice4(0),
		_bidVolume4(0), _askPrice4(0), _askVolume4(0), _bidPrice5(0), _bidVolume5(0),
		_askPrice5(0), _askVolume5(0), _averagePrice(0)
	{
	}

	void  AbstractQuotation::instrumentId(const std::string& value)
	{
		_instrumentId = value;
	}

	void AbstractQuotation::tradingDay(const std::string& value)
	{
		_tradingDay = value;
	}

	void AbstractQuotation::exchangeId(const std::string& value)
	{
		_exchangeId = value;
	}

	void AbstractQuotation::exchangeInstrumentId(const std::string& value)
	{
		_exchangeInstrumentId = value;
	}

	void AbstractQuotation::lastPrice(double value)
	{
		_lastPrice = value;
	}

	void  AbstractQuotation::prevSettlementPrice(double value)
	{
		_prevSettlementPrice = value;
	}

	void  AbstractQuotation::prevClosePrice(double value)
	{
		_prevClosePrice = value;
	}

	void AbstractQuotation::prevOpenInterest(double value)
	{
		_prevOpenInterest = value;
	}

	void AbstractQuotation::openPrice(double value)
	{
		_openPrice = value;
	}

	void AbstractQuotation::highestPrice(double value)
	{
		_highestPrice = value;
	}

	void AbstractQuotation::lowestPrice(double value)
	{
		_lowestPrice = value;
	}

	void AbstractQuotation::volume(int value)
	{
		_volume = value;
	}

	void AbstractQuotation::turnover(double value)
	{
		_turnover = value;
	}

	void AbstractQuotation::openInterest(double value)
	{
		_openInterest = value;
	}

	void AbstractQuotation::closePrice(double value)
	{
		_closePrice = value;
	}

	void AbstractQuotation::settlementPrice(double value)
	{
		_settlementPrice = value;
	}

	void AbstractQuotation::upperLimitPrice(double value)
	{
		_upperLimitPrice = value;
	}

	void AbstractQuotation::lowerLimitPrice(double value)
	{
		_lowerLimitPrice = value;
	}

	void AbstractQuotation::prevDelta(double value)
	{
		_prevDelta = value;
	}

	void AbstractQuotation::currentDelta(double value)
	{
		_currentDelta = value;
	}

	void AbstractQuotation::updateTime(const std::string& value)
	{
		_updateTime = value;
	}

	void AbstractQuotation::updateMillisecond(int value)
	{
		_updateMillisecond = value;
	}

	void AbstractQuotation::bidPrice1(double value)
	{
		_bidPrice1 = value;
	}

	void AbstractQuotation::bidVolume1(int value)
	{
		_bidVolume1 = value;
	}

	void AbstractQuotation::askPrice1(double value)
	{
		_askPrice1 = value;
	}

	void AbstractQuotation::askVolume1(int value)
	{
		_askVolume1 = value;
	}

	void AbstractQuotation::bidPrice2(double value)
	{
		_bidPrice2 = value;
	}

	void AbstractQuotation::bidVolume2(int value)
	{
		_bidVolume2 = value;
	}

	void AbstractQuotation::askPrice2(double value)
	{
		_askPrice2 = value;
	}

	void AbstractQuotation::askVolume2(int value)
	{
		_askVolume2 = value;
	}

	void AbstractQuotation::bidPrice3(double value)
	{
		_bidPrice3 = value;
	}

	void AbstractQuotation::bidVolume3(int value)
	{
		_bidVolume3 = value;
	}

	void AbstractQuotation::askPrice3(double value)
	{
		_askPrice3 = value;
	}

	void AbstractQuotation::askVolume3(int value)
	{
		_askVolume3 = value;
	}

	void AbstractQuotation::bidPrice4(double value)
	{
		_bidPrice4 = value;
	}

	void AbstractQuotation::bidVolume4(int value)
	{
		_bidVolume4 = value;
	}

	void AbstractQuotation::askPrice4(double value)
	{
		_askPrice4 = value;
	}

	void AbstractQuotation::askVolume4(int value)
	{
		_askVolume4 = value;
	}

	void AbstractQuotation::bidPrice5(double value)
	{
		_bidPrice5 = value;
	}

	void AbstractQuotation::bidVolume5(int value)
	{
		_bidVolume5 = value;
	}

	void AbstractQuotation::askPrice5(double value)
	{
		_askPrice5 = value;
	}

	void AbstractQuotation::askVolume5(int value)
	{
		_askVolume5 = value;
	}

	void  AbstractQuotation::averagePrice(double value)
	{
		_averagePrice = value;
	}

	void AbstractQuotation::actionDay(const std::string& value)
	{
		_actionDay = value;
	}
}