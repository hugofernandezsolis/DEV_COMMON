// Logger.tpp
template<typename T>
Logger& Logger::operator<<(const T& msg) {
    std::lock_guard<std::mutex> lock(mu);
    file << msg;
    return *this;
}